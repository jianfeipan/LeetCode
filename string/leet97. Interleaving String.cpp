class Solution {
private:
    bool isInterLeaveRecursive(const string &  s1, const string & s2, const string & s3, 
                               int index1, int index2, int index3)
    {
        if(index3 == s3.size()-1)
        {
            return (index2 == s2.size() && index1 == s1.size()-1 && s3[index3] == s1[index1]) 
                || (index1 == s1.size() && index2 == s2.size()-1 && s3[index3] == s2[index2]) ;
        }
        else
        {
            return (index1<s1.size() && s3[index3] == s1[index1] && isInterLeaveRecursive(s1,s2,s3,index1+1, index2, index3+1)) 
                || (index2<s2.size() && s3[index3] == s2[index2] && isInterLeaveRecursive(s1,s2,s3,index1, index2+1, index3+1));
        }
    }   
    
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s3.empty())
            return s1.empty()&&s2.empty();
        
        return isInterLeaveRecursive(s1,s2,s3,0,0,0);

    }
};
