class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> products(nums.size(), 1);
        
        {//cumulate from left   
            int product = 1;
            for(int i = 0; i<nums.size(); ++i)
            {
                products[i] = product;
                product*=nums[i];
            }
        }
        
        {//cumulate from right
            int product = 1;
            for(int i = nums.size()-1; i>=0; --i)
            {
                products[i]*=product;
                product *= nums[i];
            }
        }
        
        return products;
    }
};
