/*LeetCode Logo
Problem List

Dynamic Layout
Premium
0

avatar
131. Palindrome Partitioning
Medium
12.1K
398
Companies
Given a string s, partition s such that every 
substring
 of the partition is a 
palindrome
. Return all possible palindrome partitioning of s.

 

Example 1:

Input: s = "aab"
Output: [["a","a","b"],["aa","b"]]
Example 2:

Input: s = "a"
Output: [["a"]]
 

Constraints:

1 <= s.length <= 16
s contains only lowercase English letters.


*/

class Solution {

// /*
//     fact:
//         1 partition
//         2 every partition is palindrome

//     idea:
//         1 all possible partitions and which meet the requirements 2
//             every line between two letters could be a patition option, take or not take will make all combinations 2^(n-1)
//             aab-> aab, a|ab, aa|b, a|a|b, 
//             check all partitions are palindrome is expensive
//             O(2^(n-1) * partitionNB * partitionLen)
//         2 start from the state of "all letters are partitions and palindrome"-> every slot can be removed so the two partitions merged to one recursivly
       

// */

// private:

//     bool palindrome(const string& s){
//         for(int i = 0; i<s.size()/2; ++i){
//             if(s[i]!=s[s.size()-1-i]) return false;
//         }
//         return true;
//     }

//     bool allParlindrome(const vector<string> & partition){
//         for(const auto & s : partition){
//             if(!palindrome(s)) return false;
//         }

//         return true;
//     }

//     void tryMerge(vector<vector<string>> &partitions, const vector<string> & currentPartition, int from){
//         // cout<<"from"<<from<<":";
//         for(const auto & s:currentPartition) cout<<s<<",";
//         cout<<endl;

//         if(allParlindrome(currentPartition)) //this comparasion is expensive: we merge only once and we test all the partitions repeatedly
//             partitions.push_back(currentPartition);

//         if(from>=currentPartition.size()-1) return;

//         for(int i = from; i<currentPartition.size()-1; ++i){
//             // cout<<"i: "<<i<<" ";
//             string merged = currentPartition[i] + currentPartition[i+1];
//             // cout<<"merged: "<<merged<<endl;
//             if(allParlindrome(currentPartition)){
//                 vector<string> newPartition;
//                 newPartition.insert(newPartition.end(), currentPartition.begin(), std::next(currentPartition.begin()+i));
//                 newPartition.insert(newPartition.end(), std::next(currentPartition.begin()+i+1), currentPartition.end());
//                 newPartition[i] = merged;
//                 tryMerge(partitions, newPartition, i);// merged the ith and i+1 th, in new partition, we start from i+1
//             }
//         }
        
//     }

//     vector<vector<string>> partition_BF(string s) {//1 brut force: find all combinations and test it palindrome
//         vector<vector<string>> partitions;
//         vector<string> currentPartition;
//         for(auto c:s){
//             currentPartition.push_back({c});
//         }


//         tryMerge(partitions, currentPartition, 0);

//         return partitions;

//     }

public:
//------------------------------------------------
/*
    the recursive above is very misleading!!! this is easier to understand: 



*/

  //from "start"" th letter, I have the current partition for [0, start-i] letters, how many can I find for the rest
  void dfs(const string& s, int start, vector<string>&& path, vector<vector<string>>& ans) {
    if (start == s.length()) {//I have all s letters finished, partition finished.
      ans.push_back(path);
      return;
    }


    for (int i = start; i < s.length(); ++i)
      if (isPalindrome(s, start, i)) {    //my current partition, is already a palindrome, if next partition is also, let's continue
        path.push_back(s.substr(start, i - start + 1)); //add to the palindrom partitions
        dfs(s, i + 1, move(path), ans); //find all under this state
        path.pop_back(); // back trace and try next one
      }
  }

  bool isPalindrome(const string& s, int l, int r) {
    while (l < r)
      if (s[l++] != s[r--])
        return false;
    return true;
  }




    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        dfs(s, 0, {}, ans);
        return ans;
    }
};
