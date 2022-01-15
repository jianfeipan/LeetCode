class Solution {
public:
    int compress(vector<char>& chars) 
    {
        int compressed = 0;
        int current = 0;

        while(current<chars.size())
        {
            const int start = current;
            
            while(current<chars.size() && chars[start] == chars[current]) current++;
            
            chars[compressed++] = chars[start];
            
            int number = current-start;
            if(number>1)
            {
                stack<char> intToChar;
                while(number>0) 
                {
                    intToChar.push('0' + number%10);
                    number/=10;
                }
                while(!intToChar.empty())
                {
                    chars[compressed++] = intToChar.top();intToChar.pop();
                }
            }            
        }
        
        return compressed;
        
    }
};
