class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) 
    {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        
        unordered_map<string, vector<string>> memory;
        
        return wordBreak(s, dict, memory);
        
    }
    
    const vector<string> & wordBreak(string s, const unordered_set<string>& dict,
                             unordered_map<string, vector<string>> & memory) 
    {
        auto it = memory.find(s);
        
        if(it!=memory.end()) return it->second;
        
        vector<string> breaked;
        if(dict.count(s)) breaked.push_back(s);//attention!!!!!!!!
        string current;
        for(const auto & c : s)
        {
            current+=c;
            if(dict.count(current))
            {
                const auto &  nexts = wordBreak(s.substr(current.size()), dict, memory);
                for(const auto & next : nexts )
                {
                    breaked.push_back(current + " " + next);
                }
            }
        }
        memory[s] = breaked;
        return memory[s];
    }
};
