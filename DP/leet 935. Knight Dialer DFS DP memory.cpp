class Solution {
public:
    
    static const int LIMIT = 1e9 + 7;
    int knightDialer(int n) 
    {
        /*
        BFS n level, result to a set
        */
        vector<vector<int>> keyBoard({
            {1,2,3},
            {4,5,6},
            {7,8,9},
            {-1,0,-1}
        });
        
        memory = vector<vector<vector<int>>>(
            keyBoard.size(), vector<vector<int>>(
                keyBoard[0].size(), vector<int>(
                    n, -1
                )
            )
        );
        
        
        int count = 0;
        
        for(int lin = 0; lin<keyBoard.size(); ++lin)
        {
            for(int col = 0; col<keyBoard[lin].size(); ++col)
            {
                if(keyBoard[lin][col] != -1)
                {
                    count +=visit(keyBoard, lin, col, n);
                    count = count%LIMIT;
                }
            }
        }
        
        return count;
    }
    
    static const vector<vector<int>> & getDirections()
    {
        static const vector<vector<int>> directions({
            {-2, -1},
            {-2,  1},
            {-1, -2},
            {-1,  2},
            { 1, -2},
            { 1,  2},
            { 2, -1},
            { 2,  1}
        });
        
        return directions;
    }
    
    
    int visit( const vector<vector<int>> & keyBoard, int lin, int col, int n)
    {
        if(0<=lin && lin<keyBoard.size() && 0<=col && col<keyBoard[lin].size())
        {
            if(keyBoard[lin][col] != -1)
            {
                auto & cache = memory[lin][col][n-1];
                if(cache!=-1) return cache;
                
                if(n == 1) return 1;
                else
                {
                    int count = 0;
                    const vector<vector<int>> & directions = getDirections();
                    for(const auto & direction : directions)
                    {
                        count+=visit(keyBoard, lin + direction[0], col + direction[1], n - 1);
                        count = count%LIMIT;
                    }
                    cache = count;
                    return count;
                }
            }
        }
        return 0;
    }
    
    vector<vector<vector<int>>> memory;
};
