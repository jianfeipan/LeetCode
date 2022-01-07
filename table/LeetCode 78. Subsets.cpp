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
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<vector<int>> subSets;
        subSets.reserve(pow(2, subSets.size()));//every element can be present or not, n element will have 2^n cases
        subSets.push_back({});
        
        for(int i = 0; i<nums.size(); ++i)
        {
            const size_t currentSize = subSets.size();
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
