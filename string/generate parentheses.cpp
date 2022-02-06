class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> generated;
        
        generateParenthesis(generated, "", 0, 0, n);
        
        return generated;
    }
    
    
    void generateParenthesis(vector<string> & generated, string current, int open, int close, int target)
    {
        if(close == target) generated.push_back(current);
        
        if(open<target)
            generateParenthesis(generated, current+"(", open+1, close, target);
        if(close<open)
            generateParenthesis(generated, current+")", open, close+1, target);
        
    }
};
