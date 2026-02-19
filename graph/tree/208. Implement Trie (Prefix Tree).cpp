/*
Design a data structure that supports adding new words and searching for existing words.

Implement the WordDictionary class:

void addWord(word) Adds word to the data structure.
bool search(word) Returns true if there is any string in the data structure that matches word or false otherwise. word may contain dots '.' where dots can be matched with any letter.
Example 1:

Input:
["WordDictionary","addWord","addWord","addWord","search","search","search","search"]
[[],["day"],["bay"],["may"],["say"],["day"],[".ay"],["b.."]]

Output:
[null, null, null, null, false, true, true, true]

Explanation:
WordDictionary wordDictionary = new WordDictionary();
wordDictionary.addWord("day");
wordDictionary.addWord("bay");
wordDictionary.addWord("may");
wordDictionary.search("say"); // return false
wordDictionary.search("day"); // return true
wordDictionary.search(".ay"); // return true
wordDictionary.search("b.."); // return true
Constraints:

1 <= word.length <= 20
word in addWord consists of lowercase English letters.
word in search consist of '.' or lowercase English letters.
There will be at most 2 dots in word for search queries.
At most 10,000 calls will be made to addWord and search.
*/

#include<array>

struct Node{
    array<Node*, 26> m_nexts;
    bool m_isWord;
};


class WordDictionary {
/*
Trie(prefix tree) 
*/
private:
    Node m_dict;

    bool _dfs(Node* current, const string & word, int pos){
        if(!current) return false;
        if(word.size() == pos) return current->m_isWord;
        
        cout<<word[pos]<<endl;

        if(word[pos] != '.'){
            return _dfs(current->m_nexts[word[pos]-'a'], word, pos+1);
        }else{
            for(Node* next : current->m_nexts){
                if(_dfs(next, word, pos+1)){
                    return true;
                }
            }
            return false;
        }
    }
public:
    WordDictionary():m_dict(){
    }
    void addWord(string word) {
        if(word.empty()) return; // exception / print / log
        Node* last = &m_dict;
        for(char c : word){
            if(last->m_nexts[c - 'a'] == nullptr)
                last->m_nexts[c - 'a'] = new Node();
            last = last->m_nexts[c - 'a'];
        }
        last->m_isWord=true;
    }
    
    bool search(string word) {
        if(word.empty()) return false; // exception / print / log
        Node * root = &m_dict;
        return _dfs(root, word, 0);
    }
};
