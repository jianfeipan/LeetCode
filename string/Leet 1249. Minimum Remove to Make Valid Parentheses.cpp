class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string result;
        stack<size_t> opens;
        for(size_t i = 0; i<s.size(); ++i)
        {
            char & c = s[i];
            
            if(c=='(')
                opens.push(i);
            else if(c==')')
            {
                if(opens.empty())
                {
                    c = '!';
                }
                else
                {
                    opens.pop();
                }
            }
        }
        
        while(!opens.empty())
        {
            s[opens.top()] = '!';
            opens.pop();
        }
        
        
        //s.erase(remove(s.begin(), s.end(), '*'), s.end());
        for(char c : s)
        {
            if(c!='!')
                result+=c;
        }
        
        return result;
        
    }
};
