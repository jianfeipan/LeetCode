class SymplifyPath {
public:
    string simplifyPath1(string path) {
        std::vector<std::string> res;
            

        string current = "";    
        for(size_t index = 1; index < path.size(); index++)
        {
            if(path[index]=='/')
            {
                if(current=="..")
                {
                    if(res.size()>0)
                        res.pop_back();
                }
                else if(current!="." && !current.empty())
                {
                    res.push_back(current);
                }
                current="";
            }
            else
            {
                current+=path[index];
            }
        }
        
        if(!current.empty())
        {
            if(current=="..")
            {
                if(res.size()>0)
                    res.pop_back();
            }
            else if(current!="." && !current.empty())
            {
                res.push_back(current);
            }
        }
        
        
        if(res.size() == 0)
            return "/";
        else{
            std::ostringstream result;
            for(const auto & s : res)
            {
                result<<"/"<<s;
            }
        
            return result.str();
        }
        
    }
    
     string simplifyPath(string path) {
        std::vector<std::string> res;
            

        auto pos = path.find('/'); 
        while(pos!=std::string::npos)
        {
            auto start = pos;
            pos = path.find('/', start+1);
            const std::string & current = path.substr(start+1, pos - start-1);

            if(current=="..")
            {
                if(res.size()>0)
                    res.pop_back();
            }
            else if(current!="." && !current.empty())
            {
                res.push_back(current);
            }
            
        }
                 
        
        if(res.size() == 0)
            return "/";
        else{
            std::ostringstream result;
            for(const auto & s : res)
            {
                result<<"/"<<s;
            }
        
            return result.str();
        }
        
    }
};
