class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> res;
        int prev;
        bool first = true;
        for (int &num : nums) {
            if (!first && prev == num)
                continue;
            else {
                first = false;
                prev = num;
            }

            int *lo = &num + 1;
            int *hi = &nums.back();
            while (lo < hi) {
                int sum = *lo + *hi + num;
                if (sum == 0) {
                    res.emplace_back(vector<int>{num, *lo, *hi});
                    while (++lo < hi && *(lo - 1) == *lo);//skip same values
                    while (--hi > lo && *hi == *(hi + 1));//skip same values
                } else if (sum < 0)
                    ++lo;
                else
                    --hi;
            }
        }
        return res;
    }
};
