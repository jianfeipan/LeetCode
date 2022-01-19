class Solution {

   /*
   We have n jobs, where every job is scheduled to be done from startTime[i] to endTime[i], obtaining a profit of profit[i].

You're given the startTime, endTime and profit arrays, return the maximum profit you can take such that there are no two jobs in the subset with overlapping time range.

If you choose a job that ends at time X you will be able to start another job that starts at time X.


[1,2,3,3]
[3,4,5,6]
[50,10,40,70]
[1,2,3,4,6]
[3,5,10,6,9]
[20,20,100,70,60]
[1,1,1]
[2,3,4]
[5,6,4]

    */
public:
   int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit)
   {
      return jobScheduling_divide_conquer_with_memory(startTime, endTime, profit);
   }
    
    
    int jobScheduling_DP_tablution(vector<int>& startTime, vector<int>& endTime, vector<int>& profit)
    {
        int n = startTime.size();
        vector<vector<int>> jobs;jobs.reserve(n);
        for (int i = 0; i < n; ++i)  jobs.push_back({endTime[i], startTime[i], profit[i]});
        
        sort(jobs.begin(), jobs.end());
        
        map<int, int> dp = {{0, 0}};
        
        for (auto& job : jobs) {
            int cur = prev(dp.upper_bound(job[1]))->second + job[2];
            if (cur > dp.rbegin()->second)
                dp[job[0]] = cur;
        }
        return dp.rbegin()->second;
    
    }


   int jobScheduling_divide_conquer_with_memory(vector<int>& startTime, vector<int>& endTime, vector<int>& profit)
   {
      vector<tuple<int, int, int>> jobs; jobs.reserve(startTime.size());

      for (size_t i = 0; i < startTime.size(); ++i) jobs.emplace_back(startTime[i], endTime[i], profit[i]);

      sort(jobs.begin(), jobs.end(),
         [](const tuple<int, int, int> & left, const tuple<int, int, int> & right) {return get<0>(left) < get<0>(right); });

      unordered_map<int, int> memory;

      return jobScheduling_recusive_with_memory(jobs, 0, memory);
   }



private:
    int jobScheduling_recusive_with_memory(const vector<tuple<int, int, int>>& jobs, int currentJob, unordered_map<int, int> memory)
    {        
        if(currentJob == jobs.size()) return 0;
        
        if (memory.count(currentJob)) return memory[currentJob];
        
        const int maxProfitIfNotTakeCurrent = jobScheduling_recusive_with_memory(jobs, currentJob+1, memory);

        int maxProfitIfTakeCurrent = get<2>(jobs[currentJob]) ;

        int nextJobIfTakeCurrent = findNext(jobs, currentJob);
        if(nextJobIfTakeCurrent!=-1) maxProfitIfTakeCurrent+=jobScheduling_recusive_with_memory(jobs, nextJobIfTakeCurrent, memory);
        
        const int maxProfit = max(maxProfitIfTakeCurrent, maxProfitIfNotTakeCurrent);

        memory[currentJob] = maxProfit;
        
        return maxProfit;
    }
    
    
    int findNext(const vector<tuple<int, int, int>>& jobs, int currentJob)
    {
        auto currentEnd = get<1>(jobs[currentJob]);
        for(int i = currentJob+1; i<jobs.size(); ++i)
        {
            if(get<0>(jobs[i]) >= currentEnd) return i;
        }
        return -1;
    }
};
