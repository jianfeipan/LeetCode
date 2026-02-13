class Solution0
{
/*
the first element have N place to go, second have N-1...
all branches reaches the end: we put all numbers, and we add this to the result
recursive?
*/
private:   
void _permute(const vector<int>& nums, 
                vector<vector<int>>& res, 
                vector<bool>& used, 
                vector<int> & current)
{
    if(current.size() == nums.size())
    {
        res.push_back(current);
        return;
    }

    for(int i = 0; i<nums.size();++i){
        if(!used[i]){
            used[i] = true;
            current.push_back(nums[i]);
            _permute(nums, res, used, current);
            current.pop_back();
            used[i] = false;
        }
    }
} 

public:
    vector<vector<int>> permute(vector<int>& nums) 
    {
        vector<vector<int>> res;
        vector<int> current;
        vector<bool> used(nums.size(), false);
        _permute(nums, res, used, current);
        return res;
    }
};

//iterative way
class Solution_iterative
{
/*
iterating on the existed res and insert he current element to all possible slots
*/

public:
    vector<vector<int>> permute(vector<int>& nums) 
    {
        vector<vector<int>> res={{}};
        for(int num:nums){
            vector<vector<int>> new_perms;
            for(const auto& p : res){
                for(int i=0; i<=p.size(); ++i){
                    vector<int> copy = p;
                    copy.insert(copy.begin() + i, num);
                    new_perms.push_back(copy);
                }

            }
            swap(res, new_perms);
        }


        return res;
    }
};


//swap
// 1 can swap with any of N-1
// 2 can swap with any of N-2...
class Solution
{
private:
    void _permute(vector<int>& nums, vector<vector<int>>& res, int from) 
    {
        if(from == nums.size()){
            res.push_back(nums);
            return;
        }

        for(int i = from; i<nums.size(); ++i){
            swap(nums[from], nums[i]);
            _permute(nums, res, from+1);
            swap(nums[from], nums[i]);
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) 
    {
        vector<vector<int>> res;
        _permute(nums, res, 0);
        return res;
    }
};

