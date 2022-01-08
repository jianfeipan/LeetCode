class Solution {
public:
    bool isPalindrome(int x) 
    {
        return isPalindrome_to_vactor(x);
    }
    
    bool isPalindrome_to_vactor(int x) 
    {
        if(x<0) return false;

        auto digits = toVector(x);
        
        for(int i = 0; i<digits.size()/2; ++i)
        {
            if(digits[i]!=digits[digits.size() - i -1])
                return false;
        }
        return true;
    }
    
    
    
    bool isPalindrome_by_reverse(int x) //INT_MAX passed
    {
        if(x<0) return false;
        
        int reversed = reverse(x);
        return x == reversed;
    }
    
private:
    vector<int> toVector(int n)
    {
        vector<int> digits;
        while(n)
        {
            digits.push_back(n%10);
            n/=10;
        }
        return digits;
    }
    
    int reverse(int x)
    {
        int reversed = 0;
        while(x)
        {
            reversed*=10;
            reversed+=x%10;
            x/=10;
        }
        return reversed;
    }
};
