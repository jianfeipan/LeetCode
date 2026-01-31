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
//better solution:
 bool checkInclusion(string s1, string s2) {
        //s2 's substring,  matches exactly all s1 letters
        // the key here is the substring must have the len(s1), so our window is fixed !! fixed !!!
        // if we have, means substring should have the same hinstogram: a:1, b:1, c:1...
        if(s2.size()<s1.size()) return false;
    
        // the histogram (Both strings only contain lowercase letters.)
        int s1Count[26]={0};
        int s2Count[26]={0};
        for(int i = 0; i<s1.size(); ++i){
            ++s1Count[s1[i]-'a'];
            ++s2Count[s2[i]-'a'];
        }

        int matches = 0;
        for(int i = 0; i<26; ++i){
            if(s1Count[i] == s2Count[i]) ++matches;
        }
        
        int left = 0; 
        int right = s1.size()-1;
        while(right<s2.size()){
            if(matches == 26) return true;

            ++right;
            ++s2Count[s2[right]-'a'];
            if(s2Count[s2[right]-'a'] == s1Count[s2[right]-'a']) //from not match to match
                ++matches;
            else if(s2Count[s2[right]-'a'] - 1 == s1Count[s2[right]-'a']) //from match to not match
                --matches;
            
            --s2Count[s2[left]-'a'];
            if(s2Count[s2[left]-'a'] == s1Count[s2[left]-'a']) 
                ++matches;
            else if(s2Count[s2[left]-'a'] + 1 == s1Count[s2[left]-'a']) 
                --matches;
            ++left;
        }
        return false;
    }






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
