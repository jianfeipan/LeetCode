/*
You are given an array of integers candidates, which may contain duplicates, and a target integer target. Your task is to return a list of all unique combinations of candidates where the chosen numbers sum to target.

Each element from candidates may be chosen at most once within a combination. The solution set must not contain duplicate combinations.

You may return the combinations in any order and the order of the numbers in each combination can be in any order.

Example 1:

Input: candidates = [9,2,2,4,6,1,5], target = 8

Output: [
  [1,2,5],
  [2,2,4],
  [2,6]
]
Example 2:

Input: candidates = [1,2,3,4,5], target = 7

Output: [
  [1,2,4],
  [2,5],
  [3,4]
]
Constraints:

1 <= candidates.length <= 100
1 <= candidates[i] <= 50
1 <= target <= 30

*/

class Solution 
{
/*
difference: 
    1 not unique, 
    2 only use once
    3 don't output duplicated 

still back track -> i guess this will have duplication problem? YES
how to avoid duplication?
!!! when backtrack: push it, use it, recursive, pop it
this order cannot be changed

to avoid duplication, just when we do "not use it, we shoudld skip all the duplicated" -> wich requires a sort.
*/

private:
    void _combinationSum(const vector<int>& candidates, 
                        int target, 
                        vector<vector<int>> &res,
                        int from,
                        vector<int>& current)
    {
        if(target<0) return;
        if(target == 0)
        {
            res.push_back(current);
            return;
        }
        if(from==candidates.size()) return;

        //use current one
        current.push_back(candidates[from]);
        _combinationSum(candidates, target-candidates[from], res, from+1, current);
        current.pop_back();

        // dont use it
        // duplication: from+1 can be still the same number, so we need to skip it
        while(from+1 <candidates.size() && candidates[from] == candidates[from + 1]){
            ++from;
        }
        _combinationSum(candidates, target, res, from+1, current);
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) 
    {
        vector<vector<int>> res;
        vector<int> current;
        sort(candidates.begin(), candidates.end());
        _combinationSum(candidates, target, res, 0, current);
        return res;
    }
};
