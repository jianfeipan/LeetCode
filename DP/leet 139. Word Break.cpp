class Solution {
public:
    unordered_map<string, bool> memory;
    
    bool wordBreak(string s, vector<string>& wordDict) 
    {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        
        return wordBreak(s, dict);
    }
    
    bool wordBreak(string s, const unordered_set<string> & dict) 
    {
        if(dict.count(s)) return true;
        
        auto it = memory.find(s);
        if(it!=memory.end()) return it->second;
        
        string current;
        for(const auto & c : s)
        {
            current+=c;
            
            if(dict.count(current))
            {
                if(wordBreak(s.substr(current.size()), dict)) return memory[s] = true;
            }
        }
        memory[s] = false;
        return false;
    }

};
