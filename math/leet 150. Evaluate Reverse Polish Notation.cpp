class Solution {
public:
    int evalRPN(vector<string>& tokens) 
    {
        return evalRPN(tokens, tokens.size() -1).first;
        
    }
    
    pair<int, int> evalRPN(const vector<string>& tokens, int current)
    {
        const auto operation = tokens[current];
        
        if(operation != "+"
           && operation != "-"
           && operation != "*"
           && operation != "/")
        {
            return {stoi(tokens[current]), current - 1};
        }
        else
        {
            const auto right = evalRPN(tokens, current - 1);

            const auto left = evalRPN(tokens, right.second);
            int result = 0;
            if(operation == "+")
                result = left.first + right.first;
            else if(operation == "-")
                result = left.first - right.first;
            else if(operation == "*")
                result = left.first * right.first;
            else if(operation == "/")
                result = left.first / right.first;
            
            return {result, left.second};
        }
        

    }

};
