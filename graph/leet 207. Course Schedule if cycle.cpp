class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) //O(E + V)
    {
        /*BFS*/
        unordered_map<int, unordered_set<int>> postRequests;
        vector<int> preReqeustsCounts(numCourses, 0);
        unordered_set<int> done;
        
        for(const auto & prerequisite :  prerequisites)
        {
            if(postRequests[prerequisite[0]].insert(prerequisite[1]).second)
                ++preReqeustsCounts[prerequisite[1]];
        }
        
        queue<int> toDo;
        
        for(int course = 0; course < numCourses; ++course)
        {
            if(preReqeustsCounts[course] == 0)
            {
                toDo.push(course);
            }
        }
        
        while(!toDo.empty())//O(V)
        {
            int current = toDo.front();toDo.pop();
            
            done.insert(current);
            
            for(const auto & postRequest : postRequests[current])//O(E)
            {
                //if(!done.count(postRequest))
                {
                    if(--preReqeustsCounts[postRequest] == 0)
                    {
                        toDo.push(postRequest);
                    }
                }
            }
        }
        return done.size() == numCourses;                            
    }
    
    bool canFinish_DFS(int numCourses, vector<vector<int>>& prerequisites) 
    {
        /*
        If circle : 
        - scan one by one with DFS, mark visited, find already visited DURING a dfs means a cycle
        */
        
        unordered_map<int, unordered_set<int>> prerequests;
        unordered_set<int> done;

        
        for(const auto & prerequisite :  prerequisites)
        {
            prerequests[prerequisite[0]].insert(prerequisite[1]);
        }
            
        for(const auto & [node, requests] : prerequests)
        {
            if(!done.count(node))
            {
                if(haveCycle(node, done, prerequests))
                {
                    return false;
                }
            }
        }
        
        return true;
    }
    
    bool haveCycle(int current, 
                   unordered_set<int> & done, 
                   const unordered_map<int, unordered_set<int>> & prerequests)
    {
        unordered_set<int> toDo;
        return dfs(current, done, toDo, prerequests);
    }
    
    bool dfs(int current, 
             unordered_set<int> & done,
             unordered_set<int> & toDo, 
             const unordered_map<int, unordered_set<int>> & prerequests)
    {
        if(!done.count(current))
        {
            if(toDo.count(current)) return true;

            toDo.insert(current);

            auto it = prerequests.find(current);
            if(it!=prerequests.end())
            {
                for(const auto & prerequest : it->second)
                {
                    if(dfs(prerequest, done, toDo, prerequests))
                    {
                        return true;
                    }
                }
            }
            done.insert(current);
        }
        return false;
    }
};
