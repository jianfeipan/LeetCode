/*
Consider a vector of employees with a name and their title:
[<John, Manager>, <Sally, CTO>, <Sam, CEO>, <Drax, Engineer>, <Bob, CFO>, <Daniel, Engineer>]

And a dictionary where the keys report to the values:
{[CTO, CEO], [Manager, CTO], [Engineer, Manager], [CFO, CEO]}

Re-order the vector of employees according to the dictionary mappings. The vector of employees can be extremely big, however the dictionary only contains the title orderings.

Sample output:
[<Drax, Engineer>, <Daniel, Engineer>, <John, Manager>, <Sally, CTO>, <Bob, CFO>, <Sam, CEO>]

Note that in this case, CTO and CFO both report to CEO so they are both before CEO and above the next biggest thing, which is manager. They can also be in either order in this case.
*/
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

template<typename T, typename V>
static void print(const std::vector<pair<T, V>> & s)
{
   std::cout << "[ ";
   for (const pair<T, V> & t : s)
      std::cout << " <" << t.first <<", "<<t.second<<">, ";
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

struct ReportInfo
{
   int reportsToNb;
   unordered_set<string> titlesReportToMe;
};

vector<pair<string, string>> sortByReportOrder_indegeerCount_update(const vector<pair<string, string>> & peopleTitles, const vector<pair<string, string>> & titleOrders)
{
   /*Idea: create nodes with extra member : "report to", "who reports to me"; 
            - remove the node with prerequestsNb=0; then update the postrequesters
            - i don''t need the names, we just need to find the order of titles
   
   */
   unordered_map<string, set<string>> nameByTitle;//name need order to print
   for (const auto & nameTitle : peopleTitles)
   {
      nameByTitle[nameTitle.second].insert(nameTitle.first);
   }

   unordered_map<string, ReportInfo> titles;

   for (const auto & reportOrder : titleOrders)
   {
      titles[reportOrder.first].reportsToNb++;
      titles[reportOrder.second].titlesReportToMe.insert(reportOrder.first);
   }

   //start find who don't need report
   deque<pair<string, string>> result;
   unordered_set<string> orderedTitles;
   bool cycle = false;
   while (!cycle)
   {
      cycle = true;
      for (const auto & title : titles)
      {
         if(orderedTitles.find(title.first)==orderedTitles.end())
         {
            if (title.second.reportsToNb == 0)
            {
               cycle = false;
               for (const auto & reportsToMe : title.second.titlesReportToMe)
               {
                  --titles[reportsToMe].reportsToNb;
               }

               for (const auto & name : nameByTitle[title.first])
               {
                  result.push_front({ name, title.first });
               }

               orderedTitles.insert(title.first);


            }
         }
      }
      
   }

   return vector<pair<string, string>>(result.begin(), result.end());



}


vector<pair<string, string>> sortByReportOrder(vector<pair<string, string>> & peopleTitles, const vector<pair<string, string>> & titleOrders)
{
   return sortByReportOrder_indegeerCount_update(peopleTitles, titleOrders);
}

int main()
{
   vector<pair<string, string>> peopleTitles({
      {"John","Manager"}, 
      {"Sally", "CTO"}, 
      {"Sam","CEO"},
      {"Drax", "Engineer"},
      {"Bob","CFO"},
      {"Daniel", "Engineer"}
      });
   vector<pair<string, string>> titleOrders({
      {"CTO", "CEO" },
      { "Manager", "CTO" },
      { "Engineer", "Manager" }, 
      { "CFO", "CEO" }
      });
   print(peopleTitles);

   auto inorder = sortByReportOrder(peopleTitles,titleOrders);

   cout << "after sort:" << endl;

   print(inorder);


   return 0;
}
