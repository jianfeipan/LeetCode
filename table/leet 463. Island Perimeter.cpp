class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int perimeter = 0;
        
        if(grid.empty() || grid[0].empty()) throw invalid_argument("empty island.");
        
        for(int lin = 0; lin < grid.size(); ++lin)
        {
            perimeter += countLine(grid, lin);
        }
        
        for(int col = 0; col < grid[0].size(); ++col)
        {
            perimeter += countCol(grid, col);
        }
        
        return perimeter;
    }
    
private:
    int countLine(const vector<vector<int>>& grid, int lin)
    {
        int counter = 0;
        int prev = 0;
        for(auto cell : grid[lin])
        {
            if(cell!=prev) ++counter;
            prev = cell;
        }
        if(prev == 1) ++counter;
        return counter;
    }
    
    int countCol(const vector<vector<int>>& grid, int col)
    {
        int counter = 0;
        int prev = 0;
        for(int lin = 0; lin<grid.size();++lin)
        {
            auto cell = grid[lin][col];
            if(cell!=prev) ++counter;
            prev = cell;
        }
        if(prev == 1) ++counter;
        return counter;
    }
    
};
