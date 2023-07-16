/*
Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

There is only one repeated number in nums, return this repeated number.

You must solve the problem without modifying the array nums and uses only constant extra space.

 

Example 1:

Input: nums = [1,3,4,2,2]
Output: 2
Example 2:

Input: nums = [3,1,3,4,2]
Output: 3
*/
class Solution {

/*
fact: 
    N+1 integers in [1, n]  --> at least one duplication

idea:
    initial soltion: mark them in a vector, (histogram)

O(n)

*/
public:
    int findDuplicate(vector<int>& nums) {
        vector<int> count(nums.size(), 0);
        for(auto num : nums)
        {
            ++count[num-1];
            if(count[num-1]>1)
            {
                return num;
            }
        }
        return 0;//Should not reach here 
    }
};
