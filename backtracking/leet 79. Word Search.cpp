class Solution {
    /*
    
    
    
    [["A","B","C","E"],
     ["S","F","E","S"],
     ["A","D","E","E"]]
    
    "ABCESEEEFS"
    
    
    */
    
    
  private:
    bool _dfs(const vector<vector<char>>& board, 
                const string& word, 
                int pos, 
                vector<vector<bool>> & visited,
                int row,
                int col){
        if(pos == word.size()) return true;
        
        if(row < 0 || row >= board.size()) return false;
        if(col < 0 || col >= board[row].size()) return false;
        if(visited[row][col]) return false;
        if(board[row][col]!= word[pos]) return false;

        
        visited[row][col] = true;
        bool found =  _dfs(board, word, pos+1, visited, row+1, col) 
            || _dfs(board, word, pos+1, visited, row-1, col)
            || _dfs(board, word, pos+1, visited, row, col+1)
            || _dfs(board, word, pos+1, visited, row, col-1);
        visited[row][col] = false;//backtracking!
        
        return found;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        for(int row = 0; row<board.size(); ++row){
            for(int col = 0; col<board[row].size(); ++col){
                vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
                if(_dfs(board, word, 0, visited, row, col)) return true;
            }
        }
        return false;
    }
};
