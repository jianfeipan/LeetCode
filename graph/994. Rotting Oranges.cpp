/*
You are given an m x n grid where each cell can have one of three values:

0 representing an empty cell,
1 representing a fresh orange, or
2 representing a rotten orange.
Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.

 

Example 1:
Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
Output: 4
*/

class Solution {

/*
fact:
    spreading to four directions

idea:
    1 use the matrix it self, make a spreading update with the step number and find the max step
    2 BFS, with a visited check

*/

private:
    bool spread(int next, int line, int col, vector<vector<int>>& grid)
    {
        bool update = false;
        if(line>0) 
        {
            if(grid[line-1][col] == 1) 
            {
                grid[line-1][col] = next;
                update=true;
            }
        }

        if(line<grid.size()-1) 
        {
            if(grid[line+1][col] == 1) 
            {
                grid[line+1][col] = next;
                update=true;
            }
        }
        
        if(col > 0) 
        {
            if(grid[line][col-1] == 1) 
            {
                grid[line][col-1] = next;
                update=true;
            }
        }

        if(col<grid[line].size()-1) 
        {
            if(grid[line][col+1] == 1) 
            {
                grid[line][col+1] = next;
                update=true;
            }
        }

        return update;
    }

public:
    int orangesRotting_scan_and_spread(vector<vector<int>>& grid) 
    {
        bool update = true;
        int current = 2;
        while(update)
        {   update = false;
            for(int line = 0; line < grid.size(); ++line)
            {
                for(int col = 0; col < grid[line].size(); ++col)
                {
                    if(grid[line][col] == current)
                    {
                        if(spread(current + 1, line, col, grid)) update = true;
                        cout<<line<< ","<< col <<":"<<update<<endl;
                    }
                }
            }
            if(update)
            {
                ++current;
            }
        }
        int steps = current - 2;

        for(int line = 0; line < grid.size(); ++line)
        {
            for(int col = 0; col < grid[line].size(); ++col)
            {
                if(grid[line][col] == 1)
                {
                    return -1;
                }
            }
        }


        
        return steps;
        
    }

//BFS
    int orangesRotting(vector<vector<int>>& grid) {
        int i,j,a=grid.size(),b=grid[0].size();
        int x = 0;
        queue<vector<int>> q;
        vector<int> v;
        for(i = 0; i < a; i++){
            for(j = 0; j < b; j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                    grid[i][j] = 0;
                }
                x += (grid[i][j]==1);
            }
        }
        if(x==0)return 0;
        int ans = -1,n;
        while(!q.empty()){
            ans++;
            n = q.size();
            while(n--){v = q.front();
            q.pop();
            if(v[0]+1<a&&grid[v[0]+1][v[1]]==1){
                q.push({v[0]+1,v[1]});
                x--;
                grid[v[0]+1][v[1]]=0;
            }
            if(v[1]+1<b&&grid[v[0]][v[1]+1]==1){
                q.push({v[0],v[1]+1});
                x--;
                grid[v[0]][v[1]+1]=0;
            }
            if(v[0]-1>=0&&grid[v[0]-1][v[1]]==1){
                q.push({v[0]-1,v[1]});
                x--;
                grid[v[0]-1][v[1]]=0;
            }
            if(v[1]-1>=0&&grid[v[0]][v[1]-1]==1){
                q.push({v[0],v[1]-1});
                x--;
                grid[v[0]][v[1]-1]=0;
            }}
        }
        return (x==0)?ans:-1;;
    }
};
