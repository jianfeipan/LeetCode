  class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        //not good thing to modify input, except allowed
        vector<vector<char>>& map = grid;
        
        int count = 0;
        for(int i = 0; i<map.size(); ++i)
        {
            for(int j = 0; j<map[i].size(); ++j)
            {
                if(map[i][j] == '1')
                {
                    ++count;
                    DFSVisit(map, i, j);
                }
            }

        }
        return count;
        
    }
    void DFSVisit(vector<vector<char>>& map, int i, int j)
    {
        if(map[i][j] =='1')
        {
            map[i][j] = '0';
            if(i-1>=0)
            {
                DFSVisit(map, i-1, j);
            }
            if(i+1<map.size())
            {
                DFSVisit(map, i+1, j);

            }
            if(j-1>=0)
            {
                DFSVisit(map, i, j-1);

            }
            if(j+1<map[i].size())
            {
                DFSVisit(map, i, j+1);

            }
        }
    }

    
};
