class Solution {
public:
    int findMin(vector<int> &nums) {
        //logN -> binary search
        //[3,4,5,6,1,2]
        // l-----r l-r
        // binary search find where left > right (other places we have r>l)
        int l = 0;
        int r = nums.size()-1;
        int min=nums[0];
        while(l<=r){
            int mid=l+(r-l)/2; // 防止益处
            if(nums[mid]<min){
                r=mid-1;
                min=nums[mid];
            }else{
                l=mid+1;
            }
        }
        return min;
    }
};
