/*Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.

In other words, return true if one of s1's permutations is the substring of s2.

 

Example 1:

Input: s1 = "ab", s2 = "eidbaooo"
Output: true
Explanation: s2 contains one permutation of s1 ("ba").
Example 2:

Input: s1 = "ab", s2 = "eidboaoo"
Output: false

*/

class Solution {
/*
fact:
    s1 is the shorter one, if not, falase
    substring, means in a window, letters have the same histogram as S1
idea:
    use a map as histogram of s1 letters and a sliding window to scan s2

*/


public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()) return false;

        unordered_map<char, int> target;
        for(char c : s1) ++target[c]; 

        int windwLenth = s1.size();

        int first = 0; 
        int last = 0;
        while(!target.empty() && first <= last && last<s2.size()){
            char current = s2[last];
            auto it = target.find(current);
            if(it!=target.end())
            {
                --(it->second);//last chat get in the window
                if(it->second == 0)
                {
                   target.erase(it);     
                }

                ++last;
            }
            else
            {
                if(first == last) 
                {
                    ++last;++first;
                }
                else
                {
                    ++target[s2[first]]; //first get out
                    ++first;
                }

            }

            //cout<< first << "-" <<last<<endl;

        }

        return target.empty();

    }
};
