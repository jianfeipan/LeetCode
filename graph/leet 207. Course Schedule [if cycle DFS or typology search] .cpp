class Solution_BF {

/*

it's a circle detection: do the iteration of prerequisites, 
if I got something I already visited, then the current cours cannot be finished
Solution1:
simulation: try to find a task process, then update the dependency graph, 
then to find another one who has no deps, then update then depdency graph...

numCourses=3
prerequisites=[[1,0],[1,2],[0,1]]

0 -> 1
1 -> 0, 2
2

2done
0 -> 1
1 -> 0

time O(n^3) space O(n)
*/
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<unordered_set<int>> depends(numCourses, unordered_set<int>());
        vector<unordered_set<int>> blocks(numCourses, unordered_set<int>());

        for(const auto& prerequisite : prerequisites){
            depends[prerequisite[0]].insert(prerequisite[1]);
            blocks[prerequisite[1]].insert(prerequisite[0]);
        }

        unordered_set<int> done;
        while(done.size()<numCourses){
            bool nothingToDo = true;
            for(int num=0; num<numCourses; ++num){
                if(!done.contains(num) && depends[num].empty()){
                    done.insert(num);
                    nothingToDo=false;
                    for(int blockingTask:blocks[num]){
                        depends[blockingTask].erase(num);
                    }
                }
            }

            if(nothingToDo){
                //no task can be done
                return false;
            } 
        }

        return true;
    }
};

class Solution {

/*
a simplified version of above version,
the core prblem is to find out if any task doesn't have any dependency
the simulated way is keep tracking and update the set of deps,
actually we can just use a counter of deps to do that, without update any deps set
 and think it in a reversed way: how many node do I block
*/
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> blocks(numCourses, 0);
        vector<vector<int>> depends(numCourses);

        for (auto& pre : prerequisites) {
            blocks[pre[1]]++; // one more task is blocked by me
            depends[pre[0]].push_back(pre[1]);
        }

        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (blocks[i] == 0) {
                q.push(i); // these nodes don't block any task, they are the final nodes
            }
        }

        int done = 0;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            done++;
            for (int dep : depends[node]) {
                blocks[dep]--; 
                // if q is not there, all it deps blocks one less node
                if (blocks[dep] == 0) {
                    q.push(dep);
                    // if this dependent task doesn't block any task
                    // this become another final task
                }
                // so when there is a cycle, the nodes in the cycle will 
                // NEVER become blocks[num] == 0, because it always block some other task
                // so no taks in the q and we stop the loop
            }
        }
        return done == numCourses;
    }
};



class Solution_DFS {

/*
DFS!
it's a circle detection: do the iteration of prerequisites, 
if I got something I already visited, then the current cours cannot be finished

numCourses=3
prerequisites=[[1,0],[1,2],[0,1]]

0 ->  2, 1
1 ->  2
2
use a visited set and DFS to search, if I got any other visited, it's false


*/

private:
    bool _dfs_can_finish(vector<vector<int>>& deps, vector<bool>& visited, int current){
        cout<< current<<endl;
        if(visited[current]) // cycle
            return false;
        if(deps[current].empty()) 
            return true;
        visited[current]=true;
        for(int dep : deps[current]){
            if(!_dfs_can_finish(deps, visited, dep)) 
                return false;
        }
        // this subgraph is good, no cycle,
        //!!!!  other task can still depends on current, so reset the visited
        visited[current] = false;
        // when we clear it's deps, other task come here will directly return true
        deps[current].clear();
        return true;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> deps(numCourses, vector<int>());
         for(const auto& prerequisite : prerequisites){
            deps[prerequisite[0]].push_back(prerequisite[1]);
        }
        vector<bool> visited(numCourses, false);
        for(int i=0; i<numCourses; ++i){
            if(!_dfs_can_finish(deps, visited, i)){
                return false;
            }
        }
        return true;
    }
};

