class Solution {
public:
    /**
     * @param nums: an array containing n + 1 integers which is between 1 and n
     * @return: the duplicate one
     */
    int findDuplicate(vector<int> &nums) {
        // idea1 : brut force O(N^2)
        //return findDuplication_brut_force(nums);

        //idea2 : use a vector<bool> bit map  O(N) + S: O(N)
        //return findDuplication_bit_map(nums);

        //idea3 : sort then compare next : O(NlogN) (in place sort will be S : O(1))
        //return findDuplication_sort(nums);

        //idea4 : because the nums are from N->0, we don't need the extra bigmap, just in place mark is ok O(N) S(1)
        return findDulication_index_inplace_mark(nums);

    }
private:
    int findDuplication_brut_force(const vector<int> &nums)
    {
        for(int i = 0 ; i<nums.size(); ++i)
        {
            for(int j = i+1; j<nums.size(); ++j)
            {
                if(nums.at(i) == nums.at(j))
                    return nums.at(i);
            }
        }
        return -1;
    }

    int findDuplication_bit_map(const vector<int> &nums)
    {
        vector<bool> count(nums.size(), false);

        for(int num : nums)
        {
            if(count[num]) return num;
            count[num] = true;
        }
        return -1;
    }

    int findDuplication_sort(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());

        for(int i = 0; i< nums.size()-1;++i)
        {
            if(nums[i] == nums[i+1]) return nums[i];
        }
        return -1;
    }

    int findDulication_index_inplace_mark(vector<int> &nums)
    {
        int currentIndex = 0;
        while(nums[currentIndex]!=-1)
        {
            int temp = nums[currentIndex];
            nums[currentIndex] = -1;//mark and we need to use this index, because we lost it
            currentIndex = temp;//use the index that we just earased
        }
        return currentIndex;
    }



};633 · Find the Duplicate Number
