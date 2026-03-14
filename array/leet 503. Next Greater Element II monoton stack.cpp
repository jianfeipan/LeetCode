class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        //Idea: find the max, from the max, go left with a monoton stack
        
        size_t size = nums.size();
        vector<int> nextGreaters(size, 0);
        
        int maxIndex = 0;
        
        for(size_t i = 0; i<size; ++i)
        {
            if(nums[maxIndex]<nums[i])
            {
                maxIndex = i;
            }
        }
        
        stack<int> right;//monoton stack

        for(int n = 0; n<size; ++n)
        {
            const int i =  (maxIndex - n + size)%size;
            
            while(!right.empty() && nums[i] >= right.top()) right.pop();
            
            if(!right.empty())  nextGreaters[i] = right.top();
            else                nextGreaters[i] = -1;
            
            right.push(nums[i]);
        }
        return nextGreaters;
        
        
    }
};
