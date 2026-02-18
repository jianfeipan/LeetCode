/*
Given a string s, split s into substrings where every substring is a palindrome. Return all possible lists of palindromic substrings.

You may return the solution in any order.

Example 1:

Input: s = "aab"

Output: [["a","a","b"],["aa","b"]]
Example 2:

Input: s = "a"

Output: [["a"]]
Constraints:

1 <= s.length <= 20
s contains only lowercase English letters.-
*/

class Solution {
/*
find palindrome, once found, it's a path, then to next
also try a longer string, if it's palindromw, it's another path
then backtracking


*/
private:

    bool _isPalandrome(const string & s, int left, int right){
        int i = left;
        int j = right;
        while(i<j){
            if(s[i]!=s[j]) return false;
            ++i;
            --j;
        }
        return true;
    }
    void _dfs(vector<vector<string>>& res, const string & s, int from, vector<string>& current){
        if(from == s.size()){
            res.push_back(current);
            return;
        }
        // find next palindrome from index "from"
        // one letter is palindrome
        //  then two letters? more letters?  abcdcba 
        //  move the right pointer, until find (from ) is the same as end , and verify palindrome

        int left = from;
        int right = from;
        while(right<s.size()){
            if(_isPalandrome(s, left, right)){
                current.push_back(s.substr(left, right-left+1));
                _dfs(res, s, right+1, current);
                current.pop_back();
            }
            ++right;
        }        
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> current;
        _dfs(res, s, 0, current);
        return res;
    }
};
