#include <iostream>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <optional>
#include <list>
#include <set>
#include <map>
#include <array>
#include <functional>
#include <algorithm>

using namespace std;

/*
Given List and a function (take 2 params, returns if 2 are of same group) - return list of lists that belong to same group.
bool sameGroup(int a, int b) { 
    // returns true if the elements are of same group else false.
}

*/

bool sameGroup(int a, int b) 
{
    return a+3 == b || b+3 == a; 
}

vector<vector<int>> goupe(vector<int> nums, function<bool(int, int)>)
{
    
    sort(nums.begin(), nums.end());//O(NlongN)
    
    //union find
    vector<int> parents(nums);
     
    for(size_t i = 0; i<nums.size()-1; ++i)//O(N^2)
    {
        for(size_t j = i+1; j<nums.size(); ++j)
        {
            if(sameGroup(nums[i], nums[j]))
            {
                parents[j] = min(parents[i], parents[j]);//take always smaller one as parent
            }
        }
    }
    unordered_map<int, vector<int>> groupsByParent;
    
    

    for(size_t i = 0; i<parents.size(); ++i)
    {
        groupsByParent[parents[i]].push_back(nums[i]);
    }
    
    vector<vector<int>> groups;groups.reserve(groupsByParent.size());
    
    for(const auto & goupe : groupsByParent)
    {
        groups.push_back(goupe.second);
    }
    
    return groups;
}


int main()
{
    
    const auto & groups = goupe({7,8,9,1,5,10,2,4,3,6,11},sameGroup);
   
   for(const auto & group : groups)
   {
        cout<<"[";
        for(const auto & num:group) cout<<num<<", ";
        cout<<"] , ";
   }
   cout<<endl;
}
