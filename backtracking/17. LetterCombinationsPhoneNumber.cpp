/*
Letter Combinations of a Phone Number

You are given a string digits made up of digits from 2 through 9 inclusive.

Each digit (not including 1) is mapped to a set of characters as shown below:

A digit could represent any one of the characters it maps to.

Return all possible letter combinations that digits could represent. You may return the answer in any order.



Example 1:

Input: digits = "34"

Output: ["dg","dh","di","eg","eh","ei","fg","fh","fi"]
Example 2:

Input: digits = ""

Output: []
Constraints:

0 <= digits.length <= 4
2 <= digits[i] <= 9

*/

class Solution {

/*
O(4^n)
option 1, loop on existed results
option 2 back tracking

*/
private:
 
 vector<string> keyBoard={"", "", "abc", "def", "ghi", "jkl",
                                  "mno", "qprs", "tuv", "wxyz"};

private:
    void _dfs(vector<string>& res, string digits, int from, string& current){
        if(from == digits.size()){
            if(!current.empty())
                res.push_back(current);
            return;
        }
        for(auto letter : keyBoard[digits[from]-'0']){
            current.push_back(letter);
            _dfs(res, digits, from+1, current);
            current.pop_back();
        }
    }
public:
    //iteration on the existed results
    vector<string> letterCombinations_iteration(string digits){
        if(digits.empty()) return {};

        vector<string> res{""};
        for(auto digit : digits){
            vector<string> newRes;
            for(const auto & str : res){
                for(const auto letter : keyBoard[digit-'0']){
                    newRes.push_back(str+letter);
                }
            }
            swap(res, newRes);
        }
        return res;
    }
    //back track
    vector<string> letterCombinations(string digits){
        vector<string> res;
        string current;
        _dfs(res, digits, 0, current);
        return res;
    }


};
