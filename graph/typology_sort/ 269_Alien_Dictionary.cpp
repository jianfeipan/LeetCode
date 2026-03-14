/*
Alien Dictionary
Solved 
Hard
Topics
Company Tags
Hints
There is a foreign language which uses the latin alphabet, but the order among letters is not "a", "b", "c" ... "z" as in English.

You receive a list of non-empty strings words from the dictionary, where the words are sorted lexicographically based on the rules of this new language.

Derive the order of letters in this language. If the order is invalid, return an empty string. If there are multiple valid order of letters, return any of them.

A string a is lexicographically smaller than a string b if either of the following is true:

The first letter where they differ is smaller in a than in b.
a is a prefix of b and a.length < b.length.
Example 1:

Input: ["z","o"]

Output: "zo"
Explanation:
From "z" and "o", we know 'z' < 'o', so return "zo".

Example 2:

Input: ["hrn","hrf","er","enn","rfnn"]

Output: "hernf"
Explanation:

from "hrn" and "hrf", we know 'n' < 'f'
from "hrf" and "er", we know 'h' < 'e'
from "er" and "enn", we know get 'r' < 'n'
from "enn" and "rfnn" we know 'e'<'r'
so one possibile solution is "hernf"
Constraints:

The input words will contain characters only from lowercase 'a' to 'z'.
1 <= words.length <= 100
1 <= words[i].length <= 100


idea:

two pointer comparison, letter[i] and letter[i+1]: 
  - we got a successor graph
  - we also need a counter map to know: how many letters are prerequisits
["hrn","hrf","er","enn","rfnn"]
n->f
h->e
r->n
e->r

f 1
e 1
n 1
r 1
h = 0!!!!-> need initialization
*/

#include <array>
class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        unordered_map<char, unordered_set<char>>  successors;
        unordered_map<char, int>  prerequisits;
        for (string w : words) {
            for (char c : w) {
                successors[c] = unordered_set<char>();
                prerequisits[c] = 0;
            }
        }
        for(int i=0; i<words.size()-1; ++i){
            const auto& s = words[i];
            const auto& l = words[i+1];
            const int minSize = min(s.size(), l.size());
            //在字典序（Lexicographical Order）的逻辑中，有一个核心原则：如果一个单词是另一个单词的前缀，那么较短的单词必须排在较长的单词前面。
            if(s.size() > l.size()
                && s.substr(0, minSize) == l.substr(0, minSize)){
                //invalide order
                return "";
            }
            for(int j = 0; j<minSize; ++j){
                if(s[j] != l[j]){
                    if(!successors[s[j]].contains(l[j]))
                    {
                        successors[s[j]].insert(l[j]);
                        ++prerequisits[l[j]];
                    }
                    break;
                }
            }
        }

        queue<char> q;
        for(auto& [c, prerequisit] : prerequisits){
            if(prerequisit == 0 ){
                q.push(c);
            }
        }

        string res;

        while(!q.empty()){
            char current = q.front();
            q.pop();
            res.push_back(current);
            for(char successor:successors[current]){
                --prerequisits[successor];
                if(0 == prerequisits[successor]){
                    q.push(successor);
                }
            }
        }

        //Cycle: if there is a cycle, it never goes to the Q, so we don't have it in the res
        if(res.size() < prerequisits.size()){
            return "";
        }

        return res;
    }
};
