class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        return threeSum_sort_fixed_one_then_2sum_treate_dupliccated(nums);
    }
private:  
    vector<vector<int>> threeSum_sort_fixed_one_then_2sum_treate_dupliccated(vector<int> nums) // O(N^2) -->handle duplication in loop
    {
        /*
        idea : sort, fixe one and find the two with two pointer
        */
        if(nums.size()<3) return {};
        
        vector<vector<int>> triplets;
        sort(nums.begin(), nums.end());
        
        for(size_t i = 0; i<nums.size() - 2; ++i)
        {
            if(i>0 && nums[i] == nums[i-1]) continue;
            size_t left = i+1;
            size_t right = nums.size()-1;
            while(left<right)
            {
                if(0 == nums[i] + nums[left] + nums[right])
                {
                    triplets.emplace_back(vector<int>{nums[i], nums[left], nums[right]});
                    ++left;
                    --right;
                    while(left<right && nums[left] == nums[left-1]) ++left;
                    while(left<right && nums[right] == nums[right+1]) --right;
                }
                else if(0 > nums[i] + nums[left] + nums[right])
                    ++left;
                else
                    --right;
            }
        }
        return vector<vector<int>>(triplets.begin(),triplets.end());
    }


      //the problem with middle move is the duplicaiton problem, 
    // by moving the middle one, you always have left and right  and you cannot easily avoid duplications
    // the the solution is to move the left one, and for the left, since you are going to search all the right range, 
    // you can pass the ones with same number
    vector<vector<int>> threeSum_fix_middle_not_working_because_of_duplication(vector<int>& nums) {
        // sort then pointers to move to 0 in two levels of loops
        std::sort(nums.begin(), nums.end());
        vector<vector<int>> res;

        for(int middle = 1; middle<nums.size() -1; ++middle){
            int left = 0; 
            int right = nums.size() -1;
            while(left<middle && middle < right){
                int sum = nums[left] + nums[middle] + nums[right];
                if(sum == 0){
                    res.push_back(vector<int>{nums[left], nums[middle], nums[right]});
                    ++left;
                    --right;
                }else if(sum < 0){
                    ++left;
                }else{//sum > 0
                    --right;
                }
            }
        }//O(n^2)
        
        //to avoid duplications: 
        //if the middle one is different, then it should be different

        return res;

    }

    
    
    vector<vector<int>> threeSum_sort_fixed_one_then_2sum(vector<int> nums) // O(N^2 * logN)
    {
        /*
        idea : sort, fixe one and find the two with two pointer
        */
        if(nums.size()<3) return {};
        
        set<vector<int>> triplets;
        sort(nums.begin(), nums.end());
        
        for(size_t i = 0; i<nums.size() - 2; ++i)
        {
            size_t left = i+1;
            size_t right = nums.size()-1;
            while(left<right)
            {
                if(0 == nums[i] + nums[left] + nums[right])
                {
                    triplets.insert({nums[i], nums[left], nums[right]});
                    ++left;
                    --right;
                }
                else if(0 > nums[i] + nums[left] + nums[right])
                    ++left;
                else
                    --right;
            }
        }
        return vector<vector<int>>(triplets.begin(),triplets.end());
    }

    

    vector<vector<int>> threeSum_brute_forec(vector<int> nums) //time limit O(N^3)
    {
        /*
        idea: all possibles
        */
        set<vector<int>> triplets;
        
        sort(nums.begin(), nums.end());
        
        for(int i = 0; i<nums.size(); ++i)        
            for(int j = i+1; j<nums.size(); ++j)
                for(int k = j+1; k<nums.size(); ++k)
                    if(nums[i] + nums[j] + nums[k] == 0) 
                        triplets.insert({nums[i], nums[j] ,nums[k]});
        
        return vector<vector<int>>(triplets.begin(),triplets.end());
    }
};
