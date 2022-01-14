class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        //Idea1 : sort all strings, use a map <sorted string, set<originalStrings>> to group
        
        vector<string> sortedStrs(strs);
        for_each(sortedStrs.begin(), sortedStrs.end(), [](string& str){
            sort(str.begin(), str.end());
        });
        
        map<string, vector<string>> groupStrs;
        for(size_t i = 0; i < sortedStrs.size(); ++i)
        {
            groupStrs[sortedStrs[i]].push_back(strs[i]);
        }
        
        vector<vector<string>> result;
        result.reserve(groupStrs.size());
        
        for(const auto & strPair : groupStrs)
        {
            result.push_back(strPair.second);
        }
                             
        return result;
    }
};
