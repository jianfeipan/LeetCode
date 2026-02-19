class Solution {

/*
BFS/DFS to paint all connected 1s, then go to next unvisited 1 do the same 
*/

private:
    void _dfs_visit_island(vector<vector<char>>& grid, int r, int c){
        if(r<0 || r>=grid.size() || c<0 || c>=grid[r].size()) return;

        if(grid[r][c]!='1') return;

        grid[r][c] = '.';
        _dfs_visit_island(grid, r+1, c);
        _dfs_visit_island(grid, r-1, c);
        _dfs_visit_island(grid, r, c+1);
        _dfs_visit_island(grid, r, c-1);
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int num = 0;
        for(int r=0; r<grid.size(); ++r){
            for(int c=0;c<grid[r].size(); ++c){
                if(grid[r][c]=='1'){
                    ++num;
                    _dfs_visit_island(grid, r, c);
                }
            }
        }
        return num;
    }
};
