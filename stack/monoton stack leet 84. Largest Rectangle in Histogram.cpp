class Solution {
public:
    int largestRectangleArea(vector<int>& heights) 
    {
        return largestRectangleArea_based_on_every_height(heights);
    }
    
    int largestRectangleArea_based_on_every_height(vector<int>& heights) //O(N)
    {
        //idea is to check every bar, how far it can go to left and how far go to right
        // before meeting a smaller one, so the rectangle based on hight of this bar stops here
        // index      0 1 2 3 4 5 
        // hights    [7,1,7,2,2,4]
        // left limit[0,0,2,2,2,5]
        //right limit[0,5,2,5,5,5]
        //so the max will be loop on the bars the surface is: currentHight * (rightlimit - leftLimit+1)
        using Index=int;
        const int n = heights.size();
        vector<Index> leftLimits(n, -1);
        {   
            // 1 2 6 <-8.  after 1 2 6 8
            // 1 2 6 8 <- 5 after 1 2 5
            // 1 2 5 <-2.  after 1 2 
            // monotonStack: 
            //.    > top() : just push
            //     == top(): nothing go next
            //     < top() : while top is biger, pop, and we note the last biger one.

            stack<Index> increasing;
            for(int i = 0; i<n;++i){
                while(!increasing.empty() && heights[i] <= heights[increasing.top()]){
                    increasing.pop();
                }
                if(!increasing.empty()){
                    leftLimits[i] = increasing.top();
                }
                increasing.push(i);
            }
        }
        vector<Index> rightLimits(n, n);
        {
            stack<Index> increasing;
            for(int i = n-1; i>=0;--i){
                while(!increasing.empty() && heights[i] <= heights[increasing.top()]){
                    increasing.pop();
                }
                if(!increasing.empty()){
                    rightLimits[i] = increasing.top();
                }
                increasing.push(i);
            }
        }
        // for(int left:leftLimits) cout<<left<<',';
        // cout<<endl;
        // for(int right:rightLimits) cout<<right<<',';
        // cout<<endl;

        int maxSurface = 0;
        for(int i = 0; i<n; ++i){
            maxSurface = max(maxSurface, 
                             heights[i] * (rightLimits[i] - leftLimits[i] - 1));
        }
        return maxSurface;
    }

    
    int largestRectangleArea_brute_force_improved(vector<int>& heights) //O(N^2)
    {
        const size_t size = heights.size();
        unordered_map<int, unordered_map<int, int>> minHeights;
        
        for(size_t left = 0; left<=size; ++left)
        {
            int currentMin=INT_MAX;
            for(size_t right = left; right<size; ++right)
            {
                currentMin = min(currentMin, heights[right]);
                minHeights[left][right] = currentMin;
            }
        }
        
        int largest = INT_MIN;
        for(size_t left = 0; left<=size; ++left)
        {
            for(size_t right = left; right<size; ++right)
            {
                const int current = (right - left + 1) * minHeights[left][right];
                largest = max(largest, current);
            }
        }
        return largest;
    }
    
    int largestRectangleArea_brute_force(vector<int>& heights) //O(N^3)
    {
        int largest = INT_MIN;
        for(size_t left = 0; left<heights.size(); ++left)
        {
            for(size_t right = left; right<heights.size(); ++right)
            {
                int minHeight = INT_MAX;
                
                for(size_t i = left; i<=right; ++i)
                {
                    minHeight = min(minHeight, heights[i]);
                }
                
                const int current = (right - left + 1) * minHeight;
                largest = max(largest, current);
            }
        }
        return largest;
    }
};
