class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) 
    {
        if(s1.size() + s2.size() != s3.size()) return false;
        
        memory = vector<vector<int>>(s1.size() +1, vector<int>(s2.size()+1, -1));
        //return isInterleave_recusive_with_memory(s1, s2, s3);
        return isInterleave_recusive_tabulation(s1, s2, s3);
    }
    
    bool isInterleave_recusive_tabulation(const string & s1, const string & s2, const string & s3) 
    {
        vector<vector<int>> compareTable(s1.size() +1, vector<int>(s2.size()+1, 0));
        
        for(size_t lin = 0; lin< compareTable.size(); ++lin)
        {
            for(size_t col = 0; col< compareTable[lin].size(); ++col)
            {
                //[lin, col] can come from two possibile statu : [lin-1, col], or [lin, col - 1] : we need one of this be true and the letter matches in s3
                
                if(lin == 0 && col ==0 ) compareTable[lin][col] = 1;
                else if(lin==0)//this means take nothing from left,and all letters from right
                {
                    if(col>0)
                        compareTable[lin][col] =  compareTable[lin][col-1] && s3[lin+col-1] == s2[col-1];
                }
                else if(col == 0)
                {
                    if(lin>0)
                        compareTable[lin][col] =  compareTable[lin-1][col] && s3[lin+col-1] == s1[lin-1];
                }
                else
                {
                    compareTable[lin][col] =    (compareTable[lin-1][col] && s3[lin+col-1] == s1[lin-1])//take s1 word
                                            ||  (compareTable[lin][col-1] && s3[lin+col-1] == s2[col-1]); //take s2 word
                }
            }
        }
        
        return compareTable.back().back();//last value is 
        
    }

    
    bool isInterleave_recusive_with_memory(const string & s1, const string & s2, const string & s3) 
    {
        return isInterleave(s1, s2, s3, 0, 0, 0); 
    }

    
private:
    bool isInterleave(const string & s1, const string & s2, const string & s3, size_t p1, size_t p2, size_t p3)
    {
        
        if(memory[p1][p2] != -1) return memory[p1][p2];
        
        if(p1 == s1.size() && p2 == s2.size() && p3==s3.size())
        {
            memory[p1][p2] = 1;
            return true;
        }
        
        
        if(p3 < s3.size())
        {
            memory[p1][p2] =   (p1<s1.size() && s1[p1] == s3[p3] && isInterleave(s1, s2, s3, p1 + 1, p2, p3 + 1)) 
                            || (p2<s2.size() && s2[p2] == s3[p3] && isInterleave(s1, s2, s3, p1, p2 + 1, p3 + 1));  
            //when doing this mean we will have deuplicated computations   !!!!!!!!!!! --> DP problem       
        }
        else
            memory[p1][p2] = 0;
        
        return memory[p1][p2];
    }
    
private:
    vector<vector<int>> memory;

};
