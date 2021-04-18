class Solution {
    
private:
    //recutivly, but will have radondant computes
    int waysToDecode(const string & s, size_t index)
    {

        if(index >= s.size())
            return 1;

        int res = 0;
        //by one
        
        const char & c = s[index];

        int num = c - '0';
        if(num>0 && num<=26)
        {
            res += waysToDecode(s, index+1);
        }
        
        //by two
        if(index<=s.size() -2)
        {
            if(num==1 || num== 2)
            {

                const char & c1 = s[index+1];
                int num1 =  c1 - '0';
                num = num*10 + num1;
                
                if(num>0 && num<=26)
                {
                    res += waysToDecode(s, index+2);//duplicated computation 
                }
                
            }
        }
        return res; 
    }
    
public:
    int numDecodings_timeout(string s) 
    {
        
        return waysToDecode(s, 0);

    }
    
    //Backtracking
    int numDecodings(string s) 
    {
        std::vector<int> res(s.size(), 0);
        res[s.size() -1] = s[s.size()-1] == '0' ? 0: 1;
        
        //from trail to head
        bool canUseNext = s[s.size()-1] != '0';
        
        for(int index = s.size()-2; index >=0; index--)
        {
            const char & c = s[index];
            int num = c - '0';
            int next =  s[index+1]-'0';
            

            if(num == 0)
            {
                if(next==0 || index==0)
                    return 0;
                res[index]=res[index+1];
            }
            else
            {
                if(next == 0)
                {

                     if(num == 1 || num == 2)
                     {
                         res[index]=max(res[index+1], 1);
                         canUseNext = false;
                     }
                     else
                     {
                         return 0;
                     }
                     
                }
                
                else
                {
                    res[index]=res[index+1];
                    if(canUseNext)
                    {

                        if(num*10 + next <=26)
                        {
                            if(index+2<s.size())
                                res[index]+=res[index+2];
                            else
                                res[index]+=1;
                        }
                    }
                    
                    canUseNext = true;
                    
                }
            }
            
            
            
        }
        
        return res[0];

    }
};
