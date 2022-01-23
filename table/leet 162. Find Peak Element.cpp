class Solution {
public:
    int findPeakElement(vector<int>& nums) 
    {
        //first decending point is a peak
        return findPeak(nums, 0, nums.size()-1);
    }
    
    int findPeak(vector<int>& nums, int from, int to)
    {
        if(from == to) return from;
        
        int mid = (from+to)>>1;
        
        if(nums[mid] < nums[mid+1]) return findPeak(nums, mid+1, to);//on mid point, it rises, so the peak is on the right
        else                        return findPeak(nums, from, mid);
        
    }
 
};
