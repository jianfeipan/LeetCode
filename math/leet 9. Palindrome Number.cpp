class Solution {
public:
    bool isPalindrome(int x) 
    {
        return isPalindrome_by_half_reverse(x);
    }
    
    bool isPalindrome_to_vactor(int x) //O(logN) S:O(logN)
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
    
    bool isPalindrome_by_half_reverse(int x) //INT_MAX will NOT passed //    O(logN) S:O(1)
    {
        if(x < 0 || (x % 10 == 0 && x != 0)) 
        {
            return false;
        }
        
        int reversed = 0;
        while(x>reversed)//DONT NEED TO ALL, just a half is ok
        {
            reversed*=10;
            reversed+=x%10;    
            x/=10;
        }
        
        return x == reversed || x==reversed/10;
        
        
    }
    
    bool isPalindrome_by_reverse(int x) //INT_MAX passed //O(logN) S:O(1)
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
