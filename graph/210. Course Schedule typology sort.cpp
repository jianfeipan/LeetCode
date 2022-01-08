class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        std::map<int, std::set<int>> graph;
        for(const auto & dep : prerequisites)
        {
            graph[dep[0]].insert(dep[1]);
        }
        
        vector<int> sequence;
        sequence.reserve(numCourses);
        
        std::vector<bool> courseIsInSequence(numCourses, false);
        
        for(int i = 0; i<numCourses; ++i)
        {
            if(!courseIsInSequence[i])
            {
                std::vector<bool> visited(numCourses, false);
                if(DFSHasCycle(i, graph, visited, courseIsInSequence, sequence))
                {
                    return {};
                }
            }
        }
        
        return sequence;
    }
    
private : 
    bool DFSHasCycle(int current, 
             std::map<int, std::set<int>> & graph, 
             std::vector<bool> & visited, 
             std::vector<bool> & courseIsInSequence, 
             std::vector<int> & sequence)
    {
        visited[current] = true;
        for(int dep : graph[current])
        { 
            if(!courseIsInSequence[dep])//taken courses can be considered as we don't have this dependency anymore!!!!!!
            {
                if(visited[dep])
                //if still get to on node in the path, there is a cycle, the case 1->2->3, 1->0->3, while 3 will not be a cycle becasue it was taken and filtered by the if above
                    return true;
                
                if(DFSHasCycle(dep, graph, visited, courseIsInSequence, sequence))
                {
                    return true;
                }
            }
        }
        
        if(!courseIsInSequence[current])
        {
            sequence.push_back(current);
            courseIsInSequence[current] = true;
        }
        
        return false;
    }
};
