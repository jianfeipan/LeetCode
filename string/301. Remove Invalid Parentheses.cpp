class Solution {
public:
    vector<string> removeInvalidParentheses(string s) 
    {
        return removeInvalidParentheses_recusive_backTrack(s);
    }
    //Idea: rcusively generate all possible validated strings see which are min 
    vector<string> removeInvalidParentheses_recusive_backTrack(string s) 
    {
        set<string> results;
        
        recusiveCollectResults(s, results, 0, "", 0, 0, 0);
        
        return vector<string>(results.begin(), results.end());
    }
    
private:
    void recusiveCollectResults(const string & s,
                                set<string> & results,
                                int removeCount,
                                string currentSolution,
                                int currentIndex,
                                int openCount,
                                int closeCount)
    {
        //collect solutions if finish and valid : how to check if valid ? open == close
        if(currentIndex == s.size() &&  openCount == closeCount)
        {   
            //current solution is better    
            //cout<< currentSolution<< ": [" <<openCount<<", "<<closeCount<<"] removed "<< removeCount <<endl;
            if(removeCount<minRemoveCount)
            {
                results.clear();
                results.insert(currentSolution);
                minRemoveCount = removeCount;
            }
            else if(removeCount==minRemoveCount)
            {
                results.insert(currentSolution);
            }
        }    
        
        //generate solutions
        
        if(currentIndex<s.size())
        {
            if(s[currentIndex] != '(' && s[currentIndex] != ')')
            {
                recusiveCollectResults(s, results, removeCount, currentSolution + s[currentIndex], currentIndex+1, openCount, closeCount);
            }
            else
            {
                //branch 1 : remove current index
                recusiveCollectResults(s, results, removeCount + 1, currentSolution, currentIndex+1, openCount, closeCount);

                //branch 2 : keep current index
                if(s[currentIndex] == '(')
                {
                    recusiveCollectResults(s, results, removeCount, currentSolution+s[currentIndex], currentIndex+1, openCount+1, closeCount);
                }
                else if(s[currentIndex] == ')')
                {
                    if(openCount>closeCount)
                    {
                        recusiveCollectResults(s, results, removeCount, currentSolution+s[currentIndex], currentIndex+1, openCount, closeCount+1);
                    }
                }
            }
        }
        
    }


private:
    int minRemoveCount = INT_MAX;
};
