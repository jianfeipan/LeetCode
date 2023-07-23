
/*You are given two 0-indexed integer permutations A and B of length n.

A prefix common array of A and B is an array C such that C[i] is equal to the count of numbers that are present at or before the index i in both A and B.

Return the prefix common array of A and B.

A sequence of n integers is called a permutation if it contains all integers from 1 to n exactly once.

 

Example 1:

Input: A = [1,3,2,4], B = [3,1,2,4]
Output: [0,2,3,4]
Explanation: At i = 0: no number is common, so C[0] = 0.
At i = 1: 1 and 3 are common in A and B, so C[1] = 2.
At i = 2: 1, 2, and 3 are common in A and B, so C[2] = 3.
At i = 3: 1, 2, 3, and 4 are common in A and B, so C[3] = 4.
Example 2:

Input: A = [2,3,1], B = [3,1,2]
Output: [0,1,3]
Explanation: At i = 0: no number is common, so C[0] = 0.
At i = 1: only 3 is common in A and B, so C[1] = 1.
At i = 2: 1, 2, and 3 are common in A and B, so C[2] = 3.


*/
class Solution {

   /*
fact:
    
idea:
    bitmap to match

   */ 

private:
    int match(const vector<int>& left, const vector<int>& right)
    {
        int sum = 0;
        for(int i = 0; i<left.size(); ++i)
        {
            if(left[i] == 1 && right[i] == 1) ++sum;
            //sum+=(left[i]*right[i]); --> heavy!!!
        }
        return sum;
    }
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int> aMap(51, 0);
        vector<int> bMap(51, 0);

        vector<int> res(A.size(), 0);

        for(int i = 0; i<A.size(); ++i)
        {
            aMap[A[i]] = 1;
            bMap[B[i]] = 1;

            res[i] = match(aMap, bMap);

        }
        return res;

    }
};
