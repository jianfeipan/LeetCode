class Solution {
public:
    int subarraySum(vector<int>& nums, int k) 
    {
        return subarraySum_cumulated_sum_map(nums, k);
    }
    
private:
    int subarraySum_cumulated_sum_map(vector<int>& nums, int k)//O(N)
    {
        int count = 0; 

        map<int,int> leftCumulatedSumCount; // left cumulated sum -> count
        /*
        ( cumulated sum ) - (another left cumulated sum) = target --> we have on sub set
        */
        leftCumulatedSumCount[0]++; // empty = 0 can be first cumulated sum
        
        int currentCumulatedSum = 0;
        for(int i=0;i<nums.size();i++)
        {
            currentCumulatedSum += nums[i];
            
            if(leftCumulatedSumCount.count(currentCumulatedSum - k))//trye to find a already cumulated sum who matches ( cumulated sum ) - (another left cumulated sum) = target
                count += leftCumulatedSumCount[currentCumulatedSum-k];
            
            leftCumulatedSumCount[currentCumulatedSum]++;
        }
        return count;
    }
    
    int subarraySum_brute_force_smart_on_sum_compute(const vector<int>& nums, int k) 
    {
         /*
        idea: the sum could be intergrated in the second loop : O(N^2)
        */
        int count = 0;
        for(size_t from = 0; from<nums.size(); ++from)
        {
            int sum = 0;//sum in second loop to avoid have anohter loop
            for(size_t to = from; to<nums.size(); ++to)
            {
                sum += nums[to];
                if(sum == k) ++count;
            }
        }
        return count;
    }
    
    
    int subarraySum_brute_force(const vector<int>& nums, int k) 
    {
        /*
        idea: all posible O(N^3)
        */
        int count = 0;
        for(size_t from = 0; from<nums.size(); ++from)
        {
            for(size_t to = from; to<nums.size(); ++to)
            {
                int sum = 0;
                for(size_t i = from; i<= to; ++i)
                    sum += nums[i];
                
                if(sum == k) ++count;
            }
        }
        return count;
    }
};
