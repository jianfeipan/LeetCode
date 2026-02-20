class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> order;
        order.reserve(numCourses);

        vector<vector<int>> blocks(numCourses, vector<int>());
        vector<int> deps(numCourses, 0);
        for(const auto& pre : prerequisites){
            ++deps[pre[0]];
            blocks[pre[1]].push_back(pre[0]);
        }

        queue<int> q;
        for(int i=0; i<numCourses; ++i){
            if(deps[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int done = q.front();
            q.pop();
            order.push_back(done);

            for(int beingBlocked : blocks[done]){
                --deps[beingBlocked];
                if(deps[beingBlocked] == 0){
                    q.push(beingBlocked);
                }
            }
        }

        if(order.size() < numCourses) {
            order.clear();
        }
        return  order;
    }
};
