

#include "pch.h"
#include <iostream>
#include <stack>


#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>


using namespace std;

/*
Given a string s and a dictionary of strings wordDict, add spaces in s to construct a sentence where each word is a valid dictionary word. Return all such possible sentences in any order.

Note that the same word in the dictionary may be reused multiple times in the segmentation.



Example 1:

Input: s = "catsanddog", wordDict = ["cat","cats","and","sand","dog"]
Output: ["cats and dog","cat sand dog"]
Example 2:

Input: s = "pineapplepenapple", wordDict = ["apple","pen","applepen","pine","pineapple"]
Output: ["pine apple pen apple","pineapple pen apple","pine applepen apple"]
Explanation: Note that you are allowed to reuse a dictionary word.
Example 3:

Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
Output: []
*/

class Solution {


   //imprivement!:  sub string may be resoved sevral times: cache
public:
   vector<string> wordBreak(string s, vector<string>& wordDict)
   {
      vector<string> sentences;

      set<string> words;
      for (const auto & word : wordDict)
         words.insert(word);

      return wordBreak(s, words);
   }

private:
   unordered_map<string, vector<string>> cache;

   vector<string> wordBreak(string s, const set<string> & words)
   {
      if (cache.count(s)) return cache[s];

      vector<string> setences;

      if (words.count(s)) //a whole string is a word
         setences.push_back(s);

      for (size_t i = 0; i < s.size(); ++i)
      {
         string first = s.substr(0, i);
         if (words.count(first))
         {
            vector<string> subSetences = wordBreak(s.substr(i), words);
            for (const auto & subSetence : subSetences)
               setences.push_back(first + " " + subSetence);

         }
      }
      cache[s] = setences;
      return setences;
   }



};

template<typename T>
static void print(const std::vector<T> & v)
{
   std::cout << "[ ";
   for (const T & t : v)
      std::cout << t << ',  ';
   std::cout << "]" << std::endl;;
}


int main()
{
   Solution solution;

   string s("catsanddog");
   vector<string> wordDict = { "cat", "cats", "and", "sand", "dog" };


   auto result = solution.wordBreak(s, wordDict);
   print(result);
   return 0;
}
