class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        //idea: put everyone to A first, then see move who will save the most, then we move another....util we have a half
        //half is k person, so we need the k top diff --> maxHeap
        
        priority_queue<int> maxHeap;//by default it's a max heap
        int totalCosts = 0;
        for(const auto & cost : costs)
        {
            totalCosts += cost.at(0);
            maxHeap.push(cost.at(0) - cost.at(1));
        }

        int bestSave = 0;//by moving people from A to B
        
        for(int i = 0; i<costs.size()/2; ++i)
        {
            bestSave+=maxHeap.top(); maxHeap.pop();
        }
        
        return totalCosts - bestSave;
        
        
    }
};
