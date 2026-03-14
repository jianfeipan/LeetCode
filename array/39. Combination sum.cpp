class Solution 
{

/*
Input:
nums = [2,5,6,9]
target = 9

Output: [[2,2,5],[9]]



fact:
    nums are distinct, to get the target we can use any number multipal times.
idea:
    any number n beyond target, we can ignore them
    any number n we can used or not used. if it's used, can be multipal times 
    let's have a pointer, and recursivly move it to the right

this is called back track!!
*/

private:
void _combinationSum(const vector<int>& nums, 
                    int target, 
                    int from, 
                    vector<vector<int>>& res, 
                    vector<int> &current)
{   
    if(target == 0)
    {
        res.push_back(current);
        return;
    }
    if(target<0) return;
    if(from==nums.size()) return;

    // we can take nums[from] 0 ,1,2,3...k times
    //  try to use this num
    current.push_back(nums[from]);
    _combinationSum(nums, target-nums[from], from, res, current);

    // try to not use this num
    current.pop_back();
    _combinationSum(nums, target, from+1, res, current);
}
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) 
    {
        vector<vector<int>> res;
        vector<int> current;
        _combinationSum(nums,target, 0, res, current);
        return res;
    }


};
