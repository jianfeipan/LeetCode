class LetterCombinationsPhoneNumber {

public:
    vector<string> letterCombinations(string digits) {
        
         if (digits.empty())
            return vector<string>();
        
        std::map<char, std::string> keys = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"}, 
            {'9', "wxyz"}
        };
        

        vector<string> res(1,"");
        vector<string> seed;
        for(char digit : digits)
        {
            const string & paths = keys[digit];
            

            seed.clear();
            for(const char & path : paths)
            {
                for(const string & str : res)
                {
                    seed.push_back(str+ path);
                }
            }
            res.swap(seed);
            
            
        }
        
        return res;

    }
};
