/*A prefix tree (also known as a trie) is a tree data structure used to efficiently store and retrieve keys in a set of strings. Some applications of this data structure include auto-complete and spell checker systems.

Implement the PrefixTree class:

PrefixTree() Initializes the prefix tree object.
void insert(String word) Inserts the string word into the prefix tree.
boolean search(String word) Returns true if the string word is in the prefix tree (i.e., was inserted before), and false otherwise.
boolean startsWith(String prefix) Returns true if there is a previously inserted string word that has the prefix prefix, and false otherwise.
Example 1:

Input:
["Trie", "insert", "dog", "search", "dog", "search", "do", "startsWith", "do", "insert", "do", "search", "do"]

Output:
[null, null, true, false, true, null, true]

Explanation:
PrefixTree prefixTree = new PrefixTree();
prefixTree.insert("dog");
prefixTree.search("dog");    // return true
prefixTree.search("do");     // return false
prefixTree.startsWith("do"); // return true
prefixTree.insert("do");
prefixTree.search("do");     // return true
Constraints:

1 <= word.length, prefix.length <= 1000
word and prefix are made up of lowercase English letters.*/
#include<array>
class PrefixTree {

private:
struct Node{
    //lowercase English letters
    bool m_isWord;
    std::array<Node*, 26> m_nexts;
    Node(): m_isWord(false), m_nexts{}{

    }
};

Node m_root;
public:
    PrefixTree():m_root() {
        
    }
    
    void insert(string word) {
        Node* current = &m_root;
        for(char c : word){
            if(!current->m_nexts[c-'a']){
                current->m_nexts[c-'a'] = new Node();
            }
            current = current->m_nexts[c-'a'];
        }
        current->m_isWord = true;
        
    }
    
    bool search(string word) {
        Node* current = &m_root;
        for(char c : word){ 
            auto* next = current->m_nexts[c-'a'];
            if(!next) return false;
            current = next;
        }
        return current->m_isWord;
    }
    
    bool startsWith(string prefix) {
        Node* current = &m_root;
        for(char c : prefix){ 
            auto* next = current->m_nexts[c-'a'];
            if(!next) return false;
            current = next;
        }
        return true;
    }
};
