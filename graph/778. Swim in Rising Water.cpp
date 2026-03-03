/*
You are given a square 2-D matrix of distinct integers grid where each integer grid[i][j] represents the elevation at position (i, j).

Rain starts to fall at time = 0, which causes the water level to rise. At time t, the water level across the entire grid is t.

You may swim either horizontally or vertically in the grid between two adjacent squares if the original elevation of both squares is less than or equal to the water level at time t.

Starting from the top left square (0, 0), return the minimum amount of time it will take until it is possible to reach the bottom right square (n - 1, n - 1).

Example 1:
Input: grid = [[0,1],[2,3]]

Output: 3
Explanation: For a path to exist to the bottom right square grid[1][1] the water elevation must be at least 3. At time t = 3, the water level is 3.

Example 2:



Input: grid = [
  [0,1,2,10],
  [9,14,4,13],
  [12,3,8,15],
  [11,5,7,6]
]

Output: 8
Explanation: The water level must be at least 8 to reach the bottom right square. The path is [0, 1, 2, 4, 8, 7, 6].

Constraints:

grid.length == grid[i].length
1 <= grid.length <= 50
0 <= grid[i][j] < n^2
*/

class Solution_DFS_broutforce {

// dfs the pathes, the max grid of the path as indicator, find the smallest indicator  
// O(4^(R*C)) it's like broutforce: search all possible pathes
private:
    void _dfs(int r, int c, vector<vector<int>>& grid, int& minT, int currentMaxInPath){
        const int R = grid.size();
        const int C = grid[0].size();
        if(r>=R || r<0 || c>= C || c<0) return; 
        if(grid[r][c] == -1) return; 
        
        currentMaxInPath = max(currentMaxInPath, grid[r][c]);
        if(r==R-1 && c==C-1){
            minT = min(minT, currentMaxInPath);
            return;
        }

        int backTrack = grid[r][c];
        grid[r][c] = -1;
        
        _dfs(r+1, c, grid, minT, currentMaxInPath);
        _dfs(r, c+1, grid, minT, currentMaxInPath);
        _dfs(r-1, c, grid, minT, currentMaxInPath);
        _dfs(r, c-1, grid, minT, currentMaxInPath);
        
        grid[r][c] = backTrack;        
    }
public:
    int swimInWater(vector<vector<int>>& grid) {
        int minT = INT_MAX;
        _dfs(0, 0, grid, minT, grid[0][0]);
        return minT;
    }
};

/*
Dijkstra: 
start from 0,0, only take the "minT so far neighbors" to the group, 
all this group can be reached at 'minT so far", then chck all neighbers of the group 
take the "minT so far" neighbor add to the group
R*C nodes, every node using a minHeap to get minSmaller neighbor
until you got R-1, C-1 in the group

or Kruskal's style: 
sort all nodes, which basically are all edges, start from the smallest edge, 
start to add it, you don't really care if this contribute the the connection you finally want to connect 0,0 and R-1, C-1,
you just add them all, there will be amoment 00 R-1,c-1 is connected because of you are adding 
one edge, and since this edge is the biggeest one sofar, then the minimum cost will be this edge.

node or, edge, depends how you look them
*/

class Solution {

private:
    const vector<vector<int>> directions=
    {
        { 1,0},
        {-1,0},
        {0, 1},
        {0,-1}
    };
   
public:
    int swimInWater(vector<vector<int>>& grid) {
        //Dijkstra: start from 0,0, add smallest edge
        // complexity:O(R*C*log(R*C))
        //.      will do R*C nodes, every node will have log(R*C) for minQ pop
        // space: O(R*C) nodes
        using T=int;
        using Pos=pair<int, int>;
        using Node=pair<T, Pos>;
        auto greater=[](const Node& left, const Node& right){
            return left.first>=right.first;
        }
        priority_queue<Node, vector<Node>, dcltype(greater)> minQ(greater);
        const in R = grid.size();
        const in C = grid[0].size();

        vector<vector<bool>> visited(R, vector<int>(N, false));

        visited[0][0] = true;
        minQ.push({grid[0][0], {0, 0}});
        int currentMaxT = grid[0][0];

        while(minQ.empty()){
            const auto& closestNode = minQ.top();
            currentMaxT = max(currentMaxT, closestNode.first);

            int r=closestNode.second.first;
            int c=closestNode.second.second;
            // pushn neighbers
            for(const auto& direction: directions){
                int newR = r + direction[0];
                int newC = c + direction[1];

                if(newR>=0 && newR<R 
                && newC>=0 && newC<C
                && !visited[newR][newC]){
                    minQ.push({grid[newR][newC], {newR, newC}});
                    if(newR == R-1 && newC == C-1){
                        return max(grid[newR][newC], currentMaxT);
                    }
                }
            }
            minQ.pop();
        }
        
        return -1;// shouldn't reach here
    }
};

// kruskal: keep adding smallest edges and detect when 0 and N-1 is connected
class DSU{ // Distinct Set Union
private: 
    using Index = int;
    unordered_map<Index, Index> m_parent;
    unordered_map<Index, int> m_rank;
    const int m_n;


public:
    DSU(int n):m_n(n){

    }
    Index index(int r, int c){
        return r*m_n+c;
    }

    Index parent(const Index& i){
        Index current = i;
        while(current!=m_parent[current]){
            current = m_parent[currnet];
        }
        return current;
    }

    bool isConnected(const Index& left, const Index& right){
        return parent(left) == parent(right);
    }

    bool unionSets(const Index& left, const Index& right){
        const auto& pl = parent(left);
        const auto& pr = parent(right);

        if(pl == pr) return true;

        if(m_rank[pl] >= m_rank[pr]){
            m_rank[pl] += m_rank[pr];
            m_parent[pr] = pl;
        }else{
             m_rank[pr] += m_rank[pl];
            m_parent[pl] = pr;
        }
        return false;
    }
};

class Solution{
public:
    int swimInWater(vector<vector<int>>& grid) {
        const int R=grid.size();
        const int C=grid[0].size();

        DSU dsu(R*C);

        using Pos = pair<int, int>;
        using Node = pair<int, Pos>;
        vector<Node> edges;edges.reserve(R*C);
        for(int r=0; r<R; ++r){
            for(int c=0;c<C; ++c){
                edges.emplace_back({grid[r][c], {r, c}});
            }
        }
        sort(edges.begin(), edges.end()); // small to big on the first element

        vector<pair<int, int>> directions = {
            {0, 1}, {1, 0}, {0, -1}, {-1, 0}
        };
        
        for(auto& [t, [r,c]] : edges){
            for (auto& [dr, dc] : directions) {
                int nr = r + dr, nc = c + dc;
                if (nr >= 0 && nr < N 
                 && nc >= 0 && nc < N 
                 && grid[nr][nc] <= t) { // I only connect the nodes smaller than t
                    dsu.unionSets(r * N + c, nr * N + nc);
                }
            }
            if(dsu.isConnected( dsu.index(0, 0), dsu.index(R-1, C-1))){
                return t;
            }
        }
        return -1;// assert(false);
    }
}
