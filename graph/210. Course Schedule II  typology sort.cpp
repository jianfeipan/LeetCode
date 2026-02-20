/*
You are given an array prerequisites where prerequisites[i] = [a, b] indicates that you must take course b first if you want to take course a.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
There are a total of numCourses courses you are required to take, labeled from 0 to numCourses - 1.

Return a valid ordering of courses you can take to finish all courses. If there are many valid answers, return any of them. If it's not possible to finish all courses, return an empty array.

Example 1:

Input: numCourses = 3, prerequisites = [[1,0]]

Output: [0,1,2]
Explanation: We must ensure that course 0 is taken before course 1.

Example 2:

Input: numCourses = 3, prerequisites = [[0,1],[1,2],[2,0]]

Output: []
Explanation: It's impossible to finish all courses.

Constraints:

1 <= numCourses <= 1000
0 <= prerequisites.length <= 1000
All prerequisite pairs are unique.
*/

class Solution {

/*
use a counter for dependencie
if it's 0-> we can process it
and update the dependency counter of tasks blocked by this task, 
so we also need a strucutre to find current task blocks which tasks
then we find nother task without deps and we can process it

*/
public:
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        //prerequisites is not usable, let's read it to the data strucutre we want
        vector<int> deps(n, 0);
        vector<vector<int>> tasksBlockedBy(n, vector<int>());

        for(const auto& pre : prerequisites){
            //pre[0] depends on pre[1]
            ++deps[pre[0]];
            tasksBlockedBy[pre[1]].push_back(pre[0]);
        }

        queue<int> toProcess;
        for(int i=0; i<n; ++i){
            if(0==deps[i]){
                toProcess.push(i);
            }
        }

        vector<int> order;
        while(!toProcess.empty()){//start process free tasks
            int done = toProcess.front();
            toProcess.pop();
            order.push_back(done);

            for(int task : tasksBlockedBy[done]){
                --deps[task];
                if(0 == deps[task]){
                    toProcess.push(task);
                }
            }
        }

        if(order.size() < n) order.clear();
        return order;
    }
};
