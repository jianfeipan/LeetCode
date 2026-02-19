#include<array>
/*
Islands and Treasure

You are given a 
m
×
n
m×n 2D grid initialized with these three possible values:

-1 - A water cell that can not be traversed.
0 - A treasure chest.
INF - A land cell that can be traversed. We use the integer 2^31 - 1 = 2147483647 to represent INF.
Fill each land cell with the distance to its nearest treasure chest. If a land cell cannot reach a treasure chest then the value should remain INF.

Assume the grid can only be traversed up, down, left, or right.

Modify the grid in-place.

Example 1:

Input: [
  [2147483647,-1,0,2147483647],
  [2147483647,2147483647,2147483647,-1],
  [2147483647,-1,2147483647,-1],
  [0,-1,2147483647,2147483647]
]

Output: [
  [3,-1,0,1],
  [2,2,1,-1],
  [1,-1,2,-1],
  [0,-1,3,4]
]
Example 2:

Input: [
  [0,-1],
  [2147483647,2147483647]
]

Output: [
  [0,-1],
  [1,2]
]
Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 100
grid[i][j] is one of {-1, 0, 2147483647}

*/

class Solution {

/*
start from treasure chest, do BFS and mark the distance, distance+1 in next level...
if it's already marked, update with smaller value

multi-source-BFS
*/
private:
    array<pair<int, int>, 4> directions = {{
        { 1,0},
        {-1,0},
        {0, 1},
        {0,-1}
    }};

public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;

        for(int r=0; r<grid.size(); ++r){
            for(int c=0; c<grid[r].size(); ++c){
                if(grid[r][c] == 0){
                    q.push({r, c});
                }
            }
        }
        
        int distance = 0;
        while(!q.empty()){
            int size = q.size();
            for(int i = 0; i<size; ++i){
                const auto& pos = q.front();
                int r = pos.first;
                int c = pos.second;
                q.pop();
                grid[r][c] = min(distance, grid[r][c]);// 0 will set to 0

                for(const auto & direction:directions){
                    int nr = r+direction.first;
                    int nc = c+direction.second;
                    if(nr>=0 && nr<grid.size() && nc>=0 && nc<grid[nr].size() && grid[nr][nc]==INT_MAX){
                        q.push({nr, nc});
                    }
                }
            }
            ++distance;
        }
    }
};
