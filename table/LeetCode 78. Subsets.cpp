class Solution {
  /*
  Given an integer array nums of unique elements, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

 

Example 1:

Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
Example 2:

Input: nums = [0]
Output: [[],[0]]
  */
public:
    vector<vector<int>> subsets(vector<int>& nums)
    {
        auto result = subsets_recusive(nums, 0);
        result.push_back({});//empty cannot be manged by the recusive: because a empty combies a {1} is still {1}, this will make duplications
        return result;
    }

    vector<vector<int>> subsets_recusive(const vector<int>& nums, int from) //we can use a cache to note on from index, what are the results, to avoid duplications
    {
       if(from == nums.size()-1) return {{nums[from]}};
        
        vector<vector<int>> results;

        auto left = nums[from];
        results.push_back({left});
        vector<vector<int>> rights = subsets_recusive(nums, from + 1);
        for(auto & right : rights)
        {
            results.push_back(right);
            right.insert(right.begin(), left);
            results.push_back(right);

        }
      
        
        
        return results;

    }

    
    
    
    vector<vector<int>> subsets_combine_add_element(vector<int>& nums) {
        
        vector<vector<int>> subSets;
        subSets.reserve(pow(2, subSets.size()));//every element can be present or not, n element will have 2^n cases
        subSets.push_back({});
        
        for(int i = 0; i<nums.size(); ++i)
        {
            const size_t currentSize = subSets.size();//itering on it self, need to take care the index, here we use this size to note in next rand ,where we stop
            for(int left = 0; left<currentSize; ++left)
            {
                vector<int> combination(subSets.at(left));
                combination.push_back(nums[i]);
                subSets.push_back(combination);
            }
        }
            
        
        return subSets;
    }
};
