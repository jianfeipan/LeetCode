class Solution {
public:
    /**
     * @param n: the given number
     * @return: Sum of elements in subsets
     */
    int subSum(int n) {
        size_t sumN = 0;
        for(size_t i = 1; i<=n; ++i)
        {
            sumN+=i;
        }

        


        size_t repeatTimes = 0;
        for(size_t k = 2; k<=n; ++k)
        {
            //with k size sub set, every element will repeat C (k -1, n -1) : number of companation while one element is fixed
            //C (k -1, n -1) = (n-1)*(n-2) .... / (k-1)! --> the sum of c(k-1, n-1) is 2^(n-1) :
            //  C(k-1, n-1) means you have n-1 element and you want to take k-1, then you sum k from k = 1 to k = n so it means you have n-1 element all the possiblities of subset : for each element, you can take or not, so you get 2^(n-1)
            size_t repeatTimeK1 = 1;//pass int limitation
            size_t repeatTimeK2 = 1;
            for(size_t i = 1; i<k; ++i)
            {
                repeatTimeK1*=(n-i);
                repeatTimeK2*=i;
            }

            repeatTimes+=repeatTimeK1/repeatTimeK2;
        }

        cout<< (repeatTimes+1)<<" == " <<pow(2,n-1); 

        return sumN * pow(2, n - 1);
    }
};
