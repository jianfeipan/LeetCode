class Solution {
public:
    int findMin(vector<int>& nums) {
        size_t left = 0;
        size_t right = nums.size()-1;
        
        while(left < right)
        {
            cout<< left <<", "<<right;
            size_t mid = (left+right)>>1;
            
            if(nums[mid] > nums[mid+1]) return nums[mid+1];
            else 
                if(nums[left] > nums[mid]) right = mid;
                else left = mid+1;
        }
        
        return nums[0];
    }
};
