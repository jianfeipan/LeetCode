class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites)
    {
        /*
        Typological sort
        BFS
        
        */
        unordered_map<int, unordered_set<int>> nextSteps;
        vector<int> preRequestCounts(numCourses, 0);
        
        for(const auto & prerequisite : prerequisites)
        {
            if(nextSteps[prerequisite[1]].insert(prerequisite[0]).second)//avoid duplications
                ++preRequestCounts[prerequisite[0]];
        }
        
        vector<int> coursesOrder;coursesOrder.reserve(numCourses);
        queue<int> toDo;
        
        for(int course = 0; course < numCourses; ++course)
        {
            if(preRequestCounts[course] == 0)
            {
                toDo.push(course);
            }
        }
        
        while(!toDo.empty())
        {
            int currentCourse = toDo.front();toDo.pop();
            coursesOrder.push_back(currentCourse);
            
            for(const auto & nextStep : nextSteps[currentCourse])
            {
                if(--preRequestCounts[nextStep] == 0)
                {
                    toDo.push(nextStep);
                }
            }
        }
        if(coursesOrder.size() == numCourses) return coursesOrder;
        else return {};//cycle case
    }
};
