class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) 
    {
        return numSubmat_cumulated_line(mat);
    }
    
    int numSubmat_cumulated_line(const vector<vector<int>>& mat) //O(N^3)
    {
        vector<vector<int>> consecutiveOnesToRight(mat.size(), vector<int>(mat[0].size(), 0));
        
        for(int line = 0; line<mat.size(); ++line)
        {
            int cumulatedFromRight = 0;
            for(int col = mat[line].size() - 1; col>=0; --col)
            {
                if(mat[line][col]) ++cumulatedFromRight;
                else    cumulatedFromRight=0;
            
                consecutiveOnesToRight[line][col] = cumulatedFromRight;
            }
        }

        int count = 0;
        for(int linFrom=0; linFrom < mat.size(); ++linFrom)
        {
            for(int colFrom = 0; colFrom < mat[0].size(); ++colFrom)
            {
                int minConsecutiveOnesToright = INT_MAX;
                for(int linTo = linFrom; linTo < mat.size(); ++linTo)
                {

                    //from left topp point, cout with the cumulated table, which can tell how much consecutive 1s to right
                    /*
                    we need the min to cover right limits
                    think about: 
                    
                    11111 --> count all
                    11100 --> count 3
                    11011 --> count 2
                    11111 --> count2 !!!! : because we come from left top
                    */
                    minConsecutiveOnesToright = min(minConsecutiveOnesToright, consecutiveOnesToRight[linTo][colFrom]);
                    count+=minConsecutiveOnesToright;//only consecutive 1s to right is interested for me
                }
            }
        }
        
        return count;
    }

    
    int numSubmat_brute_force(vector<vector<int>>& mat) //O(N^4)
    {
        int count = 0;
        for(size_t linFrom=0; linFrom < mat.size(); ++linFrom)
        {
            for(size_t colFrom = 0; colFrom < mat[0].size(); ++colFrom)
            {
                if(mat[linFrom][colFrom] == 1 )
                {
                    size_t downBoundry = mat.size();
                    size_t rightBoundry  =  mat[0].size();
                    for(size_t linTo = linFrom; linTo <downBoundry;  ++linTo)
                    {
                        for(size_t colTo = colFrom; colTo <rightBoundry; ++colTo)
                        {
                            if(mat[linTo][colTo] == 1)
                                ++count;
                            else
                                rightBoundry = colTo;//0 makes a new boundry, don't worry the down boundry, if we found a 0 down the current, when we get it we will stop with rightBoundry, too
                        }
                    }
                }
            }
        }
        
        return count;
            
    }
};
