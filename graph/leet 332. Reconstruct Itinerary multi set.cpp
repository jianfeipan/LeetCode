#include "pch.h"
#include <deque>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

/*
You are given a list of airline tickets where tickets[i] = [fromi, toi] represent the departure and the arrival airports of one flight. Reconstruct the itinerary in order and return it.

All of the tickets belong to a man who departs from "JFK",
thus, the itinerary must begin with "JFK". 
If there are multiple valid itineraries, you should return the itinerary that has the smallest lexical order when read as a single string.

For example, the itinerary ["JFK", "LGA"] has a smaller lexical order than ["JFK", "LGB"].
You may assume all tickets form at least one valid itinerary. You must use all the tickets once and only once.

*/

template<typename T, typename V>
static void print(const std::vector<pair<T, V>> & s)
{
   std::cout << "[ ";
   for (const pair<T, V> & t : s)
      std::cout << " <" << t.first << ", " << t.second << ">, ";
   std::cout << "]" << std::endl;;
}

template<typename T>
static void print(const std::vector<T> & v)
{
   std::cout << "[ ";
   for (const T & t : v)
      std::cout << t << ' ';
   std::cout << "]" << std::endl;;
}





void visit(string airport, map<string, multiset<string>> & outComes, vector<string> & route)
{


   while (outComes[airport].size()) {
      string next = *outComes[airport].begin();
      outComes[airport].erase(outComes[airport].begin());
      visit(next, outComes, route);

   }
   route.push_back(airport);
}

vector<string> findItinerary(vector<vector<string>>& tickets)
{
   map<string, multiset<string>> outComes;//MUTI-set : we could have same ticket twice for a loop :)
   vector<string> route;
   for (const auto & ticket : tickets)
      outComes[ticket[0]].insert(ticket[1]);

   visit("JFK", outComes, route);
   return vector<string>(route.rbegin(), route.rend());
}

int main()
{
   vector<vector<string>> simpleflights({ 
      {"MUC","LHR"},{"JFK","MUC"},{"SFO","SJC"},{"LHR","SFO"}
      });
   vector<vector<string>> complexflights({
      {"JFK","SFO"},{"JFK","ATL"},{"SFO","ATL"},{"ATL","JFK"},{"ATL","SFO"}
      });


   //cout << endl; print(findItinerary(simpleflights));

   //cout << endl; print(findItinerary(complexflights));
   {
      vector<vector<string>> test({ { "JFK", "ATL" }, {"ATL", "JFK"} });
     // cout << endl; print(findItinerary(test));
   }
   {
      vector<vector<string>> test({ { "JFK", "KUL" }, {"JFK", "NRT"}, {"NRT", "JFK"} });
      cout << endl; print(findItinerary(test));
   }
   return 0;
}
