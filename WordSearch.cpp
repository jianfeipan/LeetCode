class Solution {
    /*
    
    
    
    [["A","B","C","E"],
     ["S","F","E","S"],
     ["A","D","E","E"]]
    
    "ABCESEEEFS"
    
    
    */
    
    
    
    
    
public:
    bool exist(vector<vector<char>>& board, string word) 
    {
        //start from very point, if first letter matched, DFS search neighbors
        if(board.empty() || board[0].empty() || word.empty()) return false;// could be throw exception
        
        for(size_t lin = 0; lin<board.size(); ++lin)
        {
            for(size_t col = 0; col < board[lin].size(); ++col)
            {
                //The same letter cell may not be used more than once.
                if(board[lin][col] == word[0])
                {
                    vector<vector<bool>> used(board.size(), vector<bool>(board[lin].size(), false));

                    if(exist_from(lin, col, board, 0, word, used))
                    {
                        return true;
                    }
                }
            }
        }
        return false;
    }
    
private:
        bool exist_from(size_t lin, size_t col, const vector<vector<char>>& board, size_t charIndex, const string & word, vector<vector<bool>> & used)
            //Used need to be passed as a copy, because different branch will have different pathes ---> this will cause a performence problem 
            // a better solution is track back in the recusive
        {
            if(lin<board.size() && col<board[lin].size()
                && !used[lin][col]
                && board[lin][col] == word[charIndex])
            {
                //cout<<lin <<", "<<col<< " : "<<word[charIndex]<<" ? "<<board[lin][col]<<endl;
                
                used[lin][col] = true; 
                if(charIndex == word.size()-1) return true;
                
                if( exist_from(lin-1, col, board, charIndex+1, word, used) 
                    || exist_from(lin+1, col, board, charIndex+1, word, used) 
                    || exist_from(lin, col-1, board, charIndex+1, word, used) 
                    || exist_from(lin, col+1, board, charIndex+1, word, used) )
                {
                    return true;
                }
                else
                {
                    used[lin][col] = false;//------> back track when failed, this branch will stop and it should reput current number aviliable for higher branch 
                    return false;
                }
                

            }
            return false;
        }
};
