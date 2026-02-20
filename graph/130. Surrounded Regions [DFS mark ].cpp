/*
You are given a 2-D matrix board containing 'X' and 'O' characters.

If a continous, four-directionally connected group of 'O's is surrounded by 'X's, it is considered to be surrounded.

Change all surrounded regions of 'O's to 'X's and do so in-place by modifying the input board.

Example 1:



Input: board = [
  ["X","X","X","X"],
  ["X","O","O","X"],
  ["X","O","O","X"],
  ["X","X","X","O"]
]

Output: [
  ["X","X","X","X"],
  ["X","X","X","X"],
  ["X","X","X","X"],
  ["X","X","X","O"]
]
Explanation: Note that regions that are on the border are not considered surrounded regions.

Constraints:

1 <= board.length, board[i].length <= 200
board[i][j] is 'X' or 'O'.

*/

class Solution {
private:
    //BFS/DFS
    //surrounded -> O cannot reach the boarder 
    // another way is to only dfs the boarder O, mark them to V, then flip all other O to X, all other Os are surranded.
    void dfs_if_reach_boarder(vector<vector<char>>& board, 
        int r, int c,
        vector<vector<bool>>& visited,
        bool& reachBoarder
    ){
        const int R = board.size();
        const int C = board[0].size();
        if(r<0 || r>=R || c<0 || c>= C 
        || visited[r][c] || board[r][c]!='O')
            return;
        
        visited[r][c] = true;
        if(R-1 == r || C-1 == c || 0 == r || 0 == c)  reachBoarder = true;
        dfs_if_reach_boarder(board, r-1, c, visited, reachBoarder);
        dfs_if_reach_boarder(board, r+1, c, visited, reachBoarder);
        dfs_if_reach_boarder(board, r, c-1, visited, reachBoarder);
        dfs_if_reach_boarder(board, r, c+1, visited, reachBoarder);
    }

    void paint(const vector<vector<bool>> & visited, 
    vector<vector<char>>& board, char to){
        const int R = board.size();
        const int C = board[0].size();
        for(int r=0; r<R; ++r){
            for(int c=0; c<C; ++c){
                if(visited[r][c]){
                    board[r][c] = to; 
                }
            }
        }
    }

public:
    void solve(vector<vector<char>>& board) {
        const int R = board.size();
        const int C = board[0].size();
        for(int r=1; r<R-1; ++r){
            for(int c=1; c<C-1; ++c){
                if(board[r][c] == 'O'){
                    vector<vector<bool>> visited(R, vector<bool>(C, false));
                    bool reachBoarder = false;
                    dfs_if_reach_boarder(board, r, c, visited, reachBoarder);
                    
                    if(!reachBoarder){
                        paint(visited, board, 'X');
                    }else{
                        paint(visited, board, 'V');//avoid going again on the visited O
                    }
                }
            }
        }
        // flip back V to O
        for(int r=0; r<R; ++r){
            for(int c=0; c<C; ++c){
                if(board[r][c] == 'V'){
                    board[r][c] = 'O'; 
                }
            }
        }
    }
};
