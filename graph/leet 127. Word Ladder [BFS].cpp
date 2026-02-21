class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        //BFS try to find the path
        unordered_set<string> notVisited(wordList.begin(), wordList.end());
        if(notVisited.count(endWord) == 0) return 0;
        
        queue<string> level;
        size_t depth = 1;
        level.push(beginWord);
        notVisited.erase(beginWord);
        
        while(!level.empty())//BFS: O(n) n words
        {
            int size = level.size();
            
            while(size-->0)
            {
                auto & node = level.front();
                notVisited.erase(node);

                for(int i=0; i<node.size(); ++i)//more efficient then loop the set O(m*26*1) = O(m) word length is m
                {
                    for(int j = 1; j<26; ++j)
                    {
                        string nextTo = node;
                        nextTo[i] = (nextTo[i]-'a' + j)%26 + 'a';
                        
                        if(notVisited.count(nextTo)) 
                        {
                            if(nextTo == endWord) return depth+1;
                            level.push(nextTo);
                        }
                    }
                }
                level.pop();
            }
            ++depth;
        }
        return 0;
    }

    
};
