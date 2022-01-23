class Solution {
public:
    int countPrimes(int n) {
        vector<bool> isPrime(n+1, true);
        
        int current = 0;
        for(int i = 2; i<n; ++i)
        {
            if(isPrime[i])    
            {   
                for(int factor = 1; i*factor<=n; ++factor) isPrime[i*factor] = false;
                
                ++current;
            }
        }
        
        return current;
    }
};
