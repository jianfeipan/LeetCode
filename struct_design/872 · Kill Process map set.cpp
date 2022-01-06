class Solution {
public:
    /**
     * @param pid: the process id
     * @param ppid: the parent process id
     * @param kill: a PID you want to kill
     * @return: a list of PIDs of processes that will be killed in the end
     */
    vector<int> killProcess(vector<int> &pid, vector<int> &ppid, int kill) {

        unordered_set<int> pids;
        unordered_map<int, set<int>> ppids;

        for(int i : pid)
        {
            pids.insert(i);
        }

        for(int i = 0; i < ppid.size(); ++i)
        {
            ppids[ppid[i]].insert(pid[i]);
        }

        vector<int> killed;
        
        killProcess_recusive(pids, ppids, kill, killed);

        return killed;
    }

private:
    void killProcess_recusive(const unordered_set<int> & pids, unordered_map<int, set<int>> & ppids, int kill, vector<int> & killed)
    {         
        if(pids.find(kill) != pids.end())
        {
            killed.push_back(kill);

            auto it = ppids.find(kill);
            if(it!=ppids.end())
            {
                for(int pid : it->second)
                    killProcess_recusive(pids, ppids, pid, killed);
            }
        }
    }
};
