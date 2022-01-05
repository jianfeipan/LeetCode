class Solution {
public:
    /**
     * @param x: the base number
     * @param n: the power number
     * @return: the result
     */
    double myPow(double x, int n) 
    {
        if(x==0) return n==0 ? 1 : 0;

        if(n<0)
        {
            if(n==INT_MIN)//INT_MIN cannot become INT_MAX by *-1 : INT_MAX+INT_MIN = -1
                n = INT_MAX;
            else
                n*=-1;

            x=1/x;//change x to 1/x as input to make it clear
        }

        return myPowPositive(x , n);

    } 

private:
    double myPowPositive(double x, int n) 
    {
        
        if(n==0) return 1.;
        if(n==1) return x;
        else
        {
            double result = myPowPositive(x * x, n/2);
            if(n%2 == 1 )
                result*=x;

            return result;
        }
        
    }
};
