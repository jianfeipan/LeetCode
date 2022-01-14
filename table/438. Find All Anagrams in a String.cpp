class Solution {
    
    /*
    
    Given two strings s and p, return an array of all the start indices of p's anagrams in s. You may return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

 

Example 1:

Input: s = "cbaebabacd", p = "abc"
Output: [0,6]
Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".
Example 2:

Input: s = "abab", p = "ab"
Output: [0,1,2]
Explanation:
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab".
 

Constraints:

1 <= s.length, p.length <= 3 * 104
s and p consist of lowercase English letters.


scope : 
-can p size() > s.size ? yes : nothing found
-can p be empty ? no : exception
-can p have duplicated letters ? yes-->window will be set or counter map

idea : 
- brute force : window slid and check anagram for all pssible indexes
- two pointer window, with a map counting p letters, to check if anagram


"abab"
"ab"
"cbaebabacd"
"abc"
"a"
"ab"
    
    
    */
public:
    vector<int> findAnagrams(string s, string p) {
        return findAnagrams_sliding_window_with_map(s, p);
    }
private:
    vector<int> findAnagrams_sliding_window_with_map(const string & s, const string & p) 
    {
        if(s.empty() || p.empty() || s.size() < p.size()) return {};//throw exception
        
        vector<int> anagramSubstrs;
        
        unordered_map<char, int> charDiagram;
        for(char c : p) ++charDiagram[c];
        
        size_t to = 0, from = 0;
        int counter = charDiagram.size();//number of unique letters need to be matched
        
        while(from<s.size() && to<s.size())
        {
            while(counter>0 && to<s.size())//find the first "to" that in [from , to]  we have all the  letters
            {
                if(charDiagram.count(s[to]))
                {
                    --charDiagram[s[to]];
                    if(charDiagram[s[to]]==0) --counter;
                }
                ++to;
            }
            
            while(counter==0 && from<s.size())
            {
                if(to - from  == p.size())//I have exactly p.size() word and all the words are in this range :find anagram
                    //attention here the to is after a ++ so it's [from, to-1]
                    anagramSubstrs.push_back(from);
                
                if(charDiagram.count(s[from]))
                {
                    if(charDiagram[s[from]]==0) ++counter;
                    ++charDiagram[s[from]];
                }
                ++from;
            }
        }
        return anagramSubstrs;
    }
    
};
