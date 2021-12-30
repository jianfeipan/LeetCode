#include "pch.h"


#include <iostream>
#include <limits.h>
#include <vector>


// A utility function to print the constructed distance array
void printSolution(const std::vector<int>& distanceTo)
{
   std::cout << "Vertex \t Distance from Source" << std::endl;
   for (int i = 0; i < distanceTo.size(); ++i)
   {
      std::cout << i << " \t\t" << distanceTo[i] << std::endl;
   }
}

static int cloestNeighber(const std::vector<int>& distanceTo, const std::vector<bool>& accessableTo)
{
   int neighber = -1;
   int neighberDistance = INT_MAX;
   for (int i = 0; i < distanceTo.size(); ++i)
   {
      if (!accessableTo[i])//only neighbers not in connection set
      {
         if (distanceTo[i] < neighberDistance)
         {
            neighber = i;
            neighberDistance = distanceTo[i];
         }
      }
   }
   if (neighber < 0)
      throw new std::exception("no accesible neighber");
   return neighber;
}


void dijkstra(const std::vector<std::vector<int>> & graph, int from)
{
   const size_t size = graph.size();
   std::vector<int> distanceTo(size, INT_MAX);
   std::vector<bool> accessableTo(size, false);
   
   distanceTo[from] = 0;

   for (int count = 0; count < size - 1; ++count){

      int closest = cloestNeighber(distanceTo, accessableTo);
      std::cout << "cloest " << closest << std::endl;
      accessableTo[closest] = true;//add closest neighber into my connection set

      for (int i = 0; i < size; ++i)
      {
         //scanne all not connected nodes 
         if (!accessableTo[i])
         {
            const int & distanceFromClosestNeighber = graph[closest][i];
            //scanne all loest node's neighber
            if (distanceFromClosestNeighber > 0)
            {
               const int distanceByClosestNeighber = distanceTo[closest] + distanceFromClosestNeighber;
               if (distanceByClosestNeighber < distanceTo[i])
               {
                  distanceTo[i] = distanceByClosestNeighber;
               }
            }
         }
      }
   }

   // print the constructed distance array
   printSolution(distanceTo);
}

// driver program to test above function
int main()
{

   /* Let us create the example graph discussed above */
   std::vector<std::vector<int>> graph(
      { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } });

   dijkstra(graph, 0);

   return 0;
}
