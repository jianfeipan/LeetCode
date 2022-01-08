class Solution {
public:
    //idea1 is DFS + cycle detection
    //idea2 is store nodes and the dependency coutns (indegree), if there is a 0, we take it, then we update -> recount, if no 0, there is a cycle
    
    
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) 
    {
        
        return findOrder_node_indegree(numCourses, prerequisites);
    }
    
    vector<int> findOrder_node_indegree(int numCourses, vector<vector<int>>& prerequisites) 
    {
        unordered_map<int, Node> nodes;
        for (const vector<int> prerequisite: prerequisites) {
            nodes[prerequisite[1]].postRequests.push_back(prerequisite[0]);
            nodes[prerequisite[0]].preRequestNb += 1;
        }

        vector<int> order;
        
        queue<int> sources;
        //this queue is to note all the impacted nodes, which are possible nodes with  preRequestNb == 0, and they will impact other nodes
        
        //find the course with no dependency : preRequestNb == 0
        for (int i = 0; i < numCourses; ++i) 
        {
            if (nodes[i].preRequestNb == 0) 
            {
                order.push_back(i);
                sources.push(i);
            }
        }

        while (!sources.empty()) 
        {
            int num_sources = sources.size();
            for (int i = 0; i < num_sources; ++i) 
            {
                int source = sources.front();
                sources.pop();
                for (int postRequest : nodes[source].postRequests) 
                {
                    nodes[postRequest].preRequestNb -= 1;
                    if (nodes[postRequest].preRequestNb == 0) 
                    {
                        order.push_back(postRequest);
                        sources.push(postRequest);
                    }
                }
            }
        }

        return order.size() == numCourses? order : vector<int>();
    }


    vector<int> findOrder_DFS(int numCourses, vector<vector<int>>& prerequisites) //O(E+V)
    {
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
    
    struct Node {
        int preRequestNb = 0;//I depend on how many nodes
        vector<int> postRequests;//who depends on me
    };
    
    
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
