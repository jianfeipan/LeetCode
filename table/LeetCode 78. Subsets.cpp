class Solution {

/*
idea: every element can be there or not
loop from empty, all existed options append the current element making a new subset
*/
public:

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        res.push_back({});

        for(int num:nums){
            int currentSize = res.size();
            for(int j = 0; j<currentSize; ++j){
                vector<int> oldSubset = res[j];
                oldSubset.push_back(num);
                res.push_back(oldSubset);
            }
        }
        return res;
    }
};
