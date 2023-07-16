/*Given an integer array nums, return true if you can partition the array into two subsets such that the sum of the elements in both subsets is equal or false otherwise.

 

Example 1:

Input: nums = [1,5,11,5]
Output: true
Explanation: The array can be partitioned as [1, 5, 5] and [11].
Example 2:

Input: nums = [1,2,3,5]
Output: false
Explanation: The array cannot be partitioned into equal sum subsets.


*/

class Solution {
/*
fact: 
    all partitions possibility : 2^n
    sum is easy to get: we just need to find a subset with sum/2
    2 partitions means, weather inthis one or the other one

idea:
    find a subset with sum/2--> if the sum is a odd --> no way
        --> subSet(sum/2, [nums])
        DP problem : 

*/
private:
    


    bool canReachTarget(int target, const vector<int>& nums, int fromIndex, vector<vector<int>> & cache)//DP
    {   


        if(fromIndex == nums.size()) //no more element
        {
            return target == 0;
        }

        if (target == 0) return true;
        if (target < 0) return false;



        //Take or not take fromIndex value 
        auto& cached = cache[target][fromIndex];
        if(cached != -1) return cached == 0 ? false : true; 
        cached = (canReachTarget(target, nums, fromIndex+1, cache) || canReachTarget(target - nums[fromIndex], nums, fromIndex+1, cache)) ? 1 : 0; 


        return cached == 0 ? false : true;
    }


public:
    bool canPartition(vector<int>& nums) {
        int sum = std::accumulate(nums.begin(), nums.end(), 0);

        if(sum%2 == 1) return false;
        int target = sum/2;
        vector<vector<int>> cache(target+1, vector<int>(nums.size()+1, -1));
        return canReachTarget(target, nums, 0, cache);

    }
};
