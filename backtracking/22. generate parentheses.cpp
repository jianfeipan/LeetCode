/*
You are given an integer n. Return all well-formed parentheses strings that you can generate with n pairs of parentheses.

Example 1:

Input: n = 1

Output: ["()"]
Example 2:

Input: n = 3

Output: ["((()))","(()())","(())()","()(())","()()()"]
You may return the answer in any order.

Constraints:

1 <= n <= 7
*/
class Solution {
/*
fact: 
    () open and close, at any position, left side should have more opens
idea:
    back track: from []
    then deside to open or close, and we need a int to track currently opened and make sure open is more then close

complexity: time O(2^(2n)) space: O(n)
*/
private:
    void _generateParenthesis(int n, vector<string>& res, string& current, int openCount, int closeCount){
        if(openCount == n && closeCount == n){
            res.push_back(current);
            return;
        } 

        // put open(s)
        if(openCount<n){
            current+='(';
            _generateParenthesis(n, res, current, openCount+1, closeCount);
            current.pop_back();
        }

        // put close(s)
        if(closeCount<openCount){
            current+=')';
            _generateParenthesis(n, res, current, openCount, closeCount+1);
            current.pop_back();
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string current;
        _generateParenthesis(n, res, current, 0, 0);
        return res;
    }
};
