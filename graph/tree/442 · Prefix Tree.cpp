class Trie {
public:
    Trie() {
        _isWord = false;
    }
    /*
     * @param word: a word
     * @return: nothing
     */
    void insert(string &word) {
        if(!word.empty()) 
        {
            auto * currentNode = this; 
            for(char c: word)
            {
                auto it = currentNode->_nexts.find(c);
                if(it==currentNode->_nexts.end())
                {
                    currentNode->_nexts[c] = Trie();
                    currentNode = &(currentNode->_nexts[c]);  
                }
                else
                {
                    currentNode = &(it->second);
                }
            }
            currentNode->_isWord = true;
        }
    }

    /*
     * @param word: A string
     * @return: if the word is in the trie.
     */
    bool search(string &word) 
    {
        if(word.empty()) return true;
        auto currentNode = this;
        for(char c: word)
        {
           auto it = currentNode->_nexts.find(c);
           if(it==currentNode->_nexts.end()) return false;
           currentNode = &(it->second); 
        }

        return currentNode->_isWord;
    }

    /*
     * @param prefix: A string
     * @return: if there is any word in the trie that starts with the given prefix.
     */
    bool startsWith(string &prefix) 
    {
        if(prefix.empty()) return true;
        auto currentNode = this;
        for(char c: prefix)
        {
            auto it = currentNode->_nexts.find(c);
            if(it==currentNode->_nexts.end()) return false;
            currentNode = &(it->second); 
        }

        return true;
    }

private:
    map<char, Trie> _nexts;
    bool _isWord;
};
