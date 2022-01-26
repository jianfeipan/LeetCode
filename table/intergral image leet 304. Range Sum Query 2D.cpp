class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix):_intergralImage(matrix) 
    {
        
        size_t linCount = matrix.size();
        size_t colCount = matrix[0].size();
        
        for(size_t lin = 0; lin<linCount; ++lin)
        {
            int currentSum = 0;
            for(size_t col = 0; col<colCount; ++col)
            {
                currentSum+=_intergralImage[lin][col];
                _intergralImage[lin][col] = currentSum;
            }
        }
        
        for(size_t col = 0; col<colCount; ++col)
        {
            int currentSum = 0;
            for(size_t lin = 0; lin<linCount; ++lin)
            {
                currentSum+=_intergralImage[lin][col];
                _intergralImage[lin][col] = currentSum;
            }
        }
        
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) 
    {
        return _intergralImage[row2][col2] 
            - (col1 == 0             ? 0 : _intergralImage[row2][col1-1])
            - (row1 == 0             ? 0 : _intergralImage[row1-1][col2])
            + ((col1==0 || row1==0)  ? 0 : _intergralImage[row1-1][col1-1]);
    }
    
private:
    vector<vector<int>> _intergralImage;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
