class Solution {
    /*
    
    4 or 8 direction adjacent ? 4    
    
    */
    
    
public:
    
    int numIslands(vector<vector<char>>& grid) 
    {
        return numIslands_DFS(grid);
    }
    
private:
    int numIslands_DFS(vector<vector<char>> grid) 
    {    
        int islandCount = 0;
        
        for(size_t lin = 0; lin<grid.size(); ++lin)
        {
            for(size_t col = 0; col<grid[lin].size(); ++col)
            {
                if(grid[lin][col] == '1')
                {
                    ++islandCount;  
                    visit(lin, col, grid);
                }
            }
        }
        return islandCount;
    }
    
    void visit(int lin, int col, vector<vector<char>> & grid)
    {
        if(lin >=0 && lin<grid.size() && col>=0 && col<grid[lin].size())
        {
            if(grid[lin][col] == '1')
            {
                grid[lin][col] = 'X';//mark as visited
                const vector<pair<int, int>> & moves = moveInDirections();
                
                for(const auto & move : moves)
                    visit(lin + move.first, col + move.second , grid);
            }
        }
    }
    
    const static vector<pair<int, int>> moveInDirections()
    {
        static vector<pair<int, int>> directions({
            {-1, 0},
            { 1, 0},
            { 0,-1},
            { 0, 1}
        });
        return directions;
    }
};
