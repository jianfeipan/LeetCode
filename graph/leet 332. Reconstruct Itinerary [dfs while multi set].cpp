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
   route.push_back(airport);// this is very useful to inseart after the recursive call
   // for exmaple : { "JFK", "AAA" }, {"JFK", "NRT"}, {"NRT", "JFK"} 
   // or            { "JFK", "ZZZ" }, {"JFK", "NRT"}, {"NRT", "JFK"} 
   // we need to make sure J to N then back to J is in the begining
   // visit J {A N}
   //           visit A { nothing} : push A
   //           visit N {J }
   //                   visit J {nothing} push J
   //           push N
   // Push J

   // -> [A, J, N, J]

   // the while loop is magic: like who doesn't next firstly, will be put in the begining
   // then the final result is inversed
         
   
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

// multi set is really very unusual data structure, the map+couter is also doing the job
// but, the counter maganism is missing a way to search the left ticket, so here are other code detecting if we finished, if we have the next,
// and we need a bakck track because we are not sure the current path is the good one.
// but with the while loop and the psuh_back after recursive call, we don't need all these...


class Solution {
private:
    bool _dfs(map<string, map<string, int>>& fromTo,
        vector<string>& iteration, int& leftTickets
        ){
        const auto& current = iteration.back();
        if(!fromTo.contains(current)){

            return leftTickets == 0;// all tickets used, found!
        }

        for(auto& to:fromTo[current]){
            //all destinations from current 
            if(to.second>0)//not visted
            {
                --to.second;
                iteration.push_back(to.first);
                --leftTickets;
                if(_dfs(fromTo, iteration, leftTickets))
                    return true;
                iteration.pop_back();// if last path not working, back track
                ++to.second;    
                ++leftTickets;            
            }
        }
        return leftTickets ==0;// false
    }
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        map<string, map<string, int>> fromTo;
        for(const auto& ticket:tickets){
            ++fromTo[ticket[0]][ticket[1]];
        }

        vector<string> iteration; 
        iteration.reserve(tickets.size()+1);
        iteration.push_back("JFK");
        int leftTickets = tickets.size();
        _dfs(fromTo, iteration, leftTickets);
        return iteration;
    }
};


