class WordSearch {
    
    
private:
    bool existOn(const char & target, vector<vector<char>>& board, const string & word, int index, int line, int column)
    {
        const char & c = board[line][column];

        if(c==target )
        {
            vector<vector<char>> pathMap = board;
            pathMap[line][column] = '*';
            if(exist(pathMap, word, index+1, line, column))
            {
                return true;
            }
        }
        return false;
    }
    
    bool exist(vector<vector<char>>& board, const string &  word, int index, int fromLine, int fromColumn) 
    {
        const char & target = word[index];
        if(index == word.size())
            return true;
        
        //search around
        if(fromLine>0)
        {
            int line = fromLine-1;
            int column = fromColumn;
            
            if(existOn(target, board, word, index, line, column))
            {
                return true;
            }
        }
        if(fromColumn>0)
        {
            int line = fromLine;
            int column = fromColumn-1;
            
           if(existOn(target, board, word, index, line, column))
            {
                return true;
            }
        }
        if(fromLine<board.size()-1)
        {
            int line = fromLine+1;
            int column = fromColumn;
            
            if(existOn(target, board, word, index, line, column))
            {
                return true;
            }
        }
        if(fromColumn<board[fromLine].size()-1)
        {
            int line = fromLine;
            int column = fromColumn+1;
            
            if(existOn(target, board, word, index, line, column))
            {
                return true;
            }
        }
        return false;
    }
    
public:
    bool exist(vector<vector<char>>& board, string word) 
    {   
        //letter are there
        string wordCopy = word;
        for(int line = 0; line < board.size(); line++)
        {
            for(int column = 0; column < board[line].size(); column++)
            {
                std::size_t found = wordCopy.find(board[line][column]);
                if (found!=std::string::npos)
                    wordCopy.erase(found,1);
            }
        }
        
        if(!wordCopy.empty())
            return false;
        
        for(int line = 0; line < board.size(); line++)
        {
            for(int column = 0; column < board[line].size(); column++)
            {
                if(word[0] == board[line][column])
                {
                    vector<vector<char>> pathMap = board;
                    pathMap[line][column] = '*';
                    if(exist(pathMap, word, 1, line, column))
                    {
                        return true;
                    }
                }
            }
        }
        
        return false;
    }
};
