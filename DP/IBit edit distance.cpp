int Solution::minDistance(string A, string B) {

/*
https://www.interviewbit.com/problems/edit-distance/
Given two strings A and B, find the minimum number of steps required to convert A to B. (each operation is counted as 1 step.)

You have the following 3 operations permitted on a word:

Insert a character
Delete a character
Replace a character


Input Format:

The first argument of input contains a string, A.
The second argument of input contains a string, B.
Output Format:

Return an integer, representing the minimum number of steps required.
Constraints:

1 <= length(A), length(B) <= 450
Examples:

Input 1:
    A = "abad"
    B = "abac"

Output 1:
    1

Explanation 1:
    Operation 1: Replace d with c.

Input 2:
    A = "Anshuman"
    B = "Antihuman"

Output 2:
    2

Explanation 2:
    => Operation 1: Replace s with t.
    => Operation 2: Insert i.

*/
    int minDistance= 0 ;
    int i  = 0;
    for(; i< B.size(); ++i)
    {
        if(i>=A.size())
        {
            minDistance++;//only add can convert
        }
        else if(A[i] != B[i])
        {
            int minByInserting = 1+  Solution::minDistance(A.substr(i, A.size() - i), B.substr(i+1, B.size() - i - 1));
            int minByDeleting =  1 +  Solution::minDistance(A.substr(i+1, A.size() - i - 1), B.substr(i, B.size() - i));
            int minByReplacing = 1 + Solution::minDistance(A.substr(i+1, A.size() - i - 1), B.substr(i+1, B.size() - i-1)); 

            return std::min(std::min(minByDeleting, minByInserting), minByReplacing);
        }
    }

    if(A.size()>=i)
        minDistance+= (A.size()-i);

    return minDistance;
}
