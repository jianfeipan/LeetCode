class Solution {
public:
    /**
     * @param heights: a list of integers
     * @return: a integer
     */
    int trapRainWater_two_direction_count(vector<int> &heights) {
        if(heights.empty()) 
        {
            return 0;
        }


        return countFromRightToLeft(heights) + countFromLeftToRight(heights);
    }

    //stack
    int trapRainWater(vector<int> &  heights) {
        // write your code here
        if(heights.size() <= 2) {
          return 0;
        }
        
        int res = 0;
        stack<int> s;
        
        for(int i = 0; i < heights.size(); i++) {
          int curh = heights[i];
          while(!s.empty() && curh > heights[s.top()]) {
            int leftIndex = s.top();s.pop();cout<<"pop"<<leftIndex<<endl;
            if(!s.empty()) 
            {
              int h = max(min(curh, heights[s.top()]) - heights[leftIndex], 0);
              int w = i - s.top() - 1;
              res += h * w;cout<<res<<endl;
            }
          }
          s.push(i);cout<<"push"<<i<<endl;
        }
        
        return res;
    }

private:
    int countFromLeftToRight(const vector<int> &heights)
    {
        int sum = 0;
        int leftMax = heights[0];
        int currentPossibleSum = 0;


        //count from hight to low
        for(int index = 1; index<heights.size(); ++index)
        {
            const int current = heights[index];
            if(current<leftMax)
            {
                currentPossibleSum+=leftMax-current;
            }
            else if(current >= leftMax)
            {
                sum+=currentPossibleSum;
                leftMax = current;
                currentPossibleSum = 0;
            }
        }

        return sum;
    }

    int countFromRightToLeft(const vector<int> &heights)
    {
        int sum = 0;
        int leftMax = heights[heights.size()-1];
        int currentPossibleSum = 0;


        //count from hight to low
        for(int index = heights.size()-2; index>=0; --index)
        {
            const int current = heights[index];
            if(current<leftMax)
            {
                currentPossibleSum+=leftMax-current;
            }
            else if(current > leftMax)
            {
                sum+=currentPossibleSum;
                leftMax = current;
                currentPossibleSum = 0;
            }
        }

        return sum;
    }
};
