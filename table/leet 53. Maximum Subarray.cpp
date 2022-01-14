class Solution {
    
    /*
    Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

A subarray is a contiguous part of an array.

 

Example 1:

Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
    */
public:
    int maxSubArray(vector<int>& nums) {//cumulated sum 
        int maxtail = nums[0];
        int max = nums[0];
        
        for(int i = 1; i<nums.size(); ++i)
        {
            maxtail = std::max(maxtail+nums[i], nums[i]);//take i-1 max sum or not
            max = std::max(max, maxtail);
        }
        
        return max;
    }
};
