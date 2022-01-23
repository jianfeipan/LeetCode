class Solution {
struct Node
{
    unordered_set<int> _postRequests;
    unordered_set<int> _preRequests;
};
    
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, Node> jobTree;
        
        for(const auto prerequisite : prerequisites)
        {
            jobTree[prerequisite[0]]._preRequests.insert(prerequisite[1]);              
            jobTree[prerequisite[1]]._postRequests.insert(prerequisite[0]);
        }
        
        while(!jobTree.empty())
        {
            bool findDoAbleTask = false;
            for(const auto & [current, node] : jobTree)   
            {
                if(node._preRequests.empty())
                {
                    for(auto postRequest : node._postRequests)
                    {
                        jobTree[postRequest]._preRequests.erase(current);
                        cout<<jobTree[postRequest]._preRequests.size()<<endl;
                        
                    }
                    findDoAbleTask = true;
                    jobTree.erase(current);
                    break;//---------> attention the for is on this job tree, here we erase and the for will crash 
                }
            }
            if(!findDoAbleTask) return false;
        }
        
        return true;
    }
    
};
