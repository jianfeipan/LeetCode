class Solution {
public:
    int uniquePaths(int m, int n) 
    {
        return uniquePaths_DP_plus(m ,n);
    }   
    
private:
    int uniquePaths_DP_plus(int m, int n) 
        //if we see the usage of this matrix, every cell only depends really on one cell before
        //so we can use only one vector instead of the matrix, to to the incremental on it self 
    {
        vector<int> pathes(n, 1);
       for(int lin = m-2; lin>=0; --lin)
       {
           for(int col = n-2; col>=0; --col)
           {
               pathes[col] += pathes[col+1]; 
           }
       }
       
       return pathes[0];
    } 
   int uniquePaths_DP(int m, int n) 
   {
       vector<vector<int>> pathes(m, vector<int>(n, 1));
       for(int lin = m-2; lin>=0; --lin)
       {
           for(int col = n-2; col>=0; --col)
           {
               pathes[lin][col] = pathes[lin+1][col] + pathes[lin][col+1]; 
           }
       }
       
       return pathes[0][0];
   }
    
    
    
    int uniquePaths_recusive(int fromLin, int fromCol, int toLin, int toCol) 
    {
        if(fromLin == toLin || fromCol == toCol ) return 1;
        
        return uniquePaths_recusive(fromLin+1, fromCol, toLin, toCol)
            + uniquePaths_recusive(fromLin, fromCol+1, toLin, toCol);
    }
    

};
