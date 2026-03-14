
#include <algorithm>  

class Solution {
public:
    /*
    longestConsecutive_hash_set_only: only start from start point with hash set, no repeat so O(n)

    longestConsecutive_hash_set_bi_direction with earase: easy to understand, like cosumming the numbers from the set to avoid duplicating so we keep the O(n)

    longestConsecutive_hash_map solutin is abit tricky, playing with the consecutive feature.
    */



    //using has set, go only to the right, avoid duplicated couting by ignoring the "not smallest number", so always start with the smallest number in any possible consequence.
    int longestConsecutive_hash_set_only start (vector<int>& nums) {
        unordered_set<int> uniqueNums(nums.begin(), nums.end());

        int maxLen = 0;

        for(int num : nums){
            if (numSet.find(num - 1) == numSet.end())  // so smart! this is the key, we only loop on the start element, we won miss anything!
            {
                
                int len=1;
                int current = num+1;
                while(present.contains(current)){
                    ++len;
                    ++current;
                }
                if(len>maxLen) {
                    maxLen = len;
                }
            }
        }

        return maxLen;
    }
    // go with hash set, go both direction, avoid duplicated couting by removing consecutive, like consumming left and right
    int longestConsecutive_hash_set_bi_direction(vector<int>& nums) {
        
        unordered_set<int> uniqueNums(nums.begin(), nums.end());
        
        int maxLen = 0;
        
        for(auto num : nums)
        {
            if(uniqueNums.count(num))
            {
                int currenLen = 1;
                int left = num-1;
                while(uniqueNums.count(left)) 
                {
                    uniqueNums.erase(left);
                    ++currenLen;
                    --left;
                }
                
                int right = num+1;
                while(uniqueNums.count(right)) 
                {
                    uniqueNums.erase(right);
                    ++currenLen;
                    ++right;
                }
                
                maxLen = max(maxLen, currenLen);
            }
            
        }
        
        return maxLen;
        
    }

//hash map way is not so easy to understand, more like a trick playing with the consecutive feature.
int longestConsecutive_hash_map(vector<int>& nums) {
        //hash map
        unordered_map<int, int> consecCount;
        int maxLen = 0;
        for(int num : nums){
            if(consecCount[num] == 0){// this number is not counted
                consecCount[num] = consecCount[num - 1] + consecCount[num+1] +1;
                consecCount[num - consecCount[num - 1]] = consecCount[num];
                consecCount[num + consecCount[num + 1]] = consecCount[num];
                // this is very smart, we only need to update the begin and end element, becasue we are extending by +1 and -1, 
                // if there is any chance we connect two consecutive range, we connect them by the begin or end
                // for exmaple we  have  , 4,5 6, then the maps looks like : 
                /*
                    4->1    
                    
                    4->2 5->2

                    4->3 5->2 6->3


                    if we also have 0, 1, 2 which looks like 
                    0->3, 1->2, 2->3, then when we merge them with 3 comes:

                    we update consecCount[3] = consecCount[2] + consecCount[4] + 1 = 7
                    and we update the begin consecCount[3-3 = 0] = 7
                    update the end consecCount[3+3 = 6] = 7
                    so we have 0->7, ....,  6->7

                
                
                */
                maxLen = max(maxLen, consecCount[num]);
            }
        }

        return maxLen;
    }
};
