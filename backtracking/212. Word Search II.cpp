
#include<array>
class Solution_loop_word_dfs_back_track {
/*
dfs to find word (length = w) board: (m*n)
loop on words (l words):
time O( l*m*n*4*3^(w-1) )
space: O(m*n+w*l)
*/
private:
    bool _dfs(const vector<vector<char>>& board, 
                const string& word,
                int pos,
                vector<vector<char>>& visited, 
                int r, int c)
        {
            if(pos == word.size()) return true;
            if(r<0 || r>=board.size() || c<0 || c>=board[r].size()) 
                return false;
            if(visited[r][c] == '.' || board[r][c] != word[pos]) 
                return false;
            
            visited[r][c] = '.';
            if(_dfs(board, word, pos+1, visited, r+1, c)
            || _dfs(board, word, pos+1, visited, r-1, c)
            || _dfs(board, word, pos+1, visited, r, c+1)
            || _dfs(board, word, pos+1, visited, r, c-1))
                return true;

            visited[r][c] = word[pos];
            return false;
        }


    bool _find(const vector<vector<char>>& board, const string& word){
        for(int r = 0; r<board.size(); ++r){//m*n
            for(int c = 0; c<board[r].size(); ++c){
                vector<vector<char>> visited = board;
                if(_dfs(board, word, 0, visited, r, c)){//3^w
                    return true;
                }
            }
        }
        return false;
    }
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> found;
        for(const auto& word:words){//L
            if(_find(board, word)){
                found.push_back(word);
            }
        }
        return found;
    }
};
/*

optimization: 

looping in words is not optimal: 
ab, and a, share the same prefix -> prefix tree.
so let's store the input words in a prfix tree, and we can do the dft on the tree, when we got a word end,
we add the word into the result
*/

class Solution{
    private:

    struct Node{
        array<Node*, 26> nexts;
        int wordIndex;
        int refs;//avoid duplications ??
        Node():wordIndex(-1),refs(0){
            nexts.fill(nullptr);
        }
    };

    void _dfs(Node* current,
                const vector<vector<char>>& board, 
                const vector<string>& words,
                vector<vector<char>>& visited, 
                int r, int c,
                vector<string>& found)
        {
            if(r<0 || r>=board.size() || c<0 || c>=board[r].size()) 
                return;
            if(visited[r][c] == '.') 
                return;
            Node* next = current->nexts[board[r][c] - 'a'];
            if(!next) return;

            visited[r][c] = '.';
            if(next->wordIndex != -1){
                found.push_back(words[next->wordIndex]);
                next->wordIndex = -1;
                // without following also passed all tests ???
                // next->refs--;
                // if (!next->refs) {
                //     current->nexts[board[r][c] - 'a'] = nullptr;
                //     visited[r][c] = board[r][c];
                //     return;
                // }
            }

            _dfs(next, board, words, visited, r+1, c, found);
            _dfs(next, board, words, visited, r-1, c, found);
            _dfs(next, board, words, visited, r, c+1, found);
            _dfs(next, board, words, visited, r, c-1, found);

            visited[r][c] = board[r][c];
        }


    void _find(Node* root, const vector<vector<char>>& board, const vector<string>& words, vector<string>& found){
        for(int r = 0; r<board.size(); ++r){//m*n
            for(int c = 0; c<board[r].size(); ++c){
                vector<vector<char>> visited = board;
                _dfs(root, board, words, visited, r, c, found);
            }
        }
    }

    void _add(Node* last, const vector<string>& words, int index){
        last->refs++;//?????
        for(char c : words[index]){
            int currentLetter = c - 'a';
            if(nullptr == last->nexts[currentLetter]){
                last->nexts[currentLetter] = new Node();
            }
            last = last->nexts[currentLetter];
            last->refs++;
        }
        last->wordIndex = index;// if the index is not -1, it's a word, and the word is words[index]
    }
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Node root;
        for(int i=0; i<words.size(); ++i){//L
            _add(&root, words, i);
        }

        vector<string> found;
        _find(&root, board, words, found);
        return found;
    }
};
