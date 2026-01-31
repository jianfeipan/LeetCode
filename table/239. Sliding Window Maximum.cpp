/*
You are given an array of integers nums and an integer k. There is a sliding window of size k that starts at the left edge of the array. The window slides one position to the right until it reaches the right edge of the array.

Return a list that contains the maximum element in the window at each step.

Example 1:

Input: nums = [1,2,1,0,4,2,6], k = 3

Output: [2,2,4,4,6]

Explanation: 
Window position            Max
---------------           -----
[1  2  1] 0  4  2  6        2
 1 [2  1  0] 4  2  6        2
 1  2 [1  0  4] 2  6        4
 1  2  1 [0  4  2] 6        4
 1  2  1  0 [4  2  6]       6
Constraints:

1 <= nums.length <= 1000
-10,000 <= nums[i] <= 10,000
1 <= k <= nums.length
*/

class Solution {
public:

   


    //use a tree map to keep the order, so we have O(N*logK)
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        //k = 3
        // l
        // 0 1 2 3 4
        // l.  j
        vector<int> res;res.reserve(nums.size() - k +1);
        map<int, int> ordered;

        for(int i=0; i<k; ++i){
            ++ordered[nums[i]];
        }
        int left = 0;
        while(left+k<=nums.size()){
            res.push_back(ordered.rbegin()->first);
            --ordered[nums[left]];
            if(ordered[nums[left]] == 0){
                ordered.erase(nums[left]);
            }
            ++ordered[nums[left+k]];
            ++left;
        }
        return res;
    }

    // using heap solution has one problem: how do you know you top is out of your window or not? 
    // the solution is to combine the index to the pair then push it to the heap, 
    // then you can get the pop util th's in your range to have the max in the window
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> heap;
        vector<int> output;
        for (int i = 0; i < nums.size(); i++) {
            heap.push({nums[i], i});
            if (i >= k - 1) {
                while (heap.top().second <= i - k) {
                    heap.pop();
                }
                output.push_back(heap.top().first);
            }
        }
        return output;
    }


    //O(N*K)
    vector<int> maxSlidingWindow_BF(vector<int>& nums, int k) {
        //k = 3
        // l
        // 0 1 2 3 4

        vector<int> res;res.reserve(nums.size() - k +1);
        for(int left = 0; left+k<=nums.size(); ++left){
            int localMax = INT_MIN;
            for(int i = left; i<left+k; ++i){
                localMax = max(localMax, nums[i]);
            }
            res.push_back(localMax);
        }
        return res;
    }
};
