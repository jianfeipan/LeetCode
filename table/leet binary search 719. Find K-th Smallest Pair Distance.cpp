class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) 
    {
        return smallestDistancePair_sort(nums, k);
    }
    
    int smallestDistancePair_sort(vector<int>& nums, int k) 
    {
        sort(nums.begin(), nums.end());
        
        int lo = 0;
        int hi = nums[nums.size() - 1] - nums[0];
        while (lo < hi) {
            int mi = (lo + hi) / 2;//guess : middle of the range is close to the middle of the real diff
            int count = 0;
            int left = 0;
            int right = 0;
            while(right < nums.size()) 
            {
                while (nums[right] - nums[left] > mi) left++;
                //within this window, all are diffs are bigger than mid, 
                //so after this while, for a given right, we have a left position, make diff < mid
                //so all the nums between left and right, diff is smaller than mid
                count += right - left;//we are counting how many pairs whoes diff < mid with a given right 
                ++right;
            }
            //count = number of pairs with diff <= mi
            if (count >= k) hi = mi;
            else lo = mi + 1;
        }
        return lo;
    }
            
    int smallestDistancePair_brute_force(vector<int>& nums, int k) 
    {
        priority_queue<int, 
            vector<int>,
            greater<int>
        > minHeap;
        
        for(size_t i = 0; i<nums.size()-1; ++i)//O(N^2)
        {
            for(size_t j = i+1; j<nums.size(); ++j)
            {
                minHeap.push(abs(nums[j] - nums[i]));
            }
        }
        
        while(--k)//O(klogN)
        {
            minHeap.pop();
        }
        return minHeap.top();
    }
};
