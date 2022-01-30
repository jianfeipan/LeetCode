class Solution {
public:
    int largestRectangleArea(vector<int>& heights) 
    {
        return largestRectangleArea_based_on_every_height(heights);
    }
    
    int largestRectangleArea_based_on_every_height(vector<int>& heights) //O(N)
    {
        /*
        int the result, we definitly need to take at least one, so, let's see for every position, if we have to take this, what's the max : 
            this i, will have hights[i] * (r - l +1) where from l to r, all the heights are bigger or equals to heights[i]
        
        */
        
        //the first step is to find the r, and l in two vectors by monoton stack!!!
        
        vector<int> leftLimits(heights.size(), 0);    
        {
            stack<pair<int, int>> leftMins; 
            leftMins.push({-100, -1});//holder for always have a top : mark the start position of array
            for(size_t i = 0; i<heights.size(); ++i)
            {
                while(!leftMins.empty() && leftMins.top().first >= heights[i]) 
                {
                    leftMins.pop();
                }

                leftLimits[i] = leftMins.top().second;
                leftMins.push({heights[i], i});
                
            }
            
        }
        
        vector<int> rightLimits(heights.size(), 0);
        {
            stack<pair<int, int>> rightMins; 
            rightMins.push({-100, heights.size()});//holder for always have a top :mark the end position of array
            for(int i = heights.size()-1; i>=0; --i)
            {
                while(!rightMins.empty() && rightMins.top().first >= heights[i]) rightMins.pop();

                rightLimits[i] = rightMins.top().second;
                rightMins.push({heights[i], i});
            }            
        }
        

        int largest = INT_MIN;
        for(size_t i = 0; i<heights.size(); ++i)
        {
           largest = max(largest, heights[i] * (rightLimits[i] - leftLimits[i] -1) );
        }
        return largest;
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
