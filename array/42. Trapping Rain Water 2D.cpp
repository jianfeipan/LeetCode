
/*
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

 

Example 1:


Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.
Example 2:

Input: height = [4,2,0,3,2,5]
Output: 9
 

Constraints:

n == height.length
1 <= n <= 2 * 104
0 <= height[i] <= 105


*/
class Solution {
public:
    int trap(vector<int>& height) {

        //Let's only count to the right:
        // For index middle, the water traped is: 
        // max(min(leftMax, rightMax) - height[middle], 0)
        // where: left < middle < right
        // leftMax = max{height[left]}
        // rightMax = max{height[right]}
        
        //BF: O(n^2)
        //usng a vector to note current max, 
        // loop from left to right, then another verctor from right to left.

        vector<int> leftMax(height.size(), 0);
        int current_left_max = height[0];
        for(int i = 1; i< leftMax.size(); ++i){
            leftMax[i] = current_left_max;
            current_left_max = max(current_left_max, height[i]);
        }
        
        vector<int> rightMax(height.size(), 0);
        int current_right_max = height[height.size()-1];
        for(int i = height.size()-2; i>=0; --i){
            rightMax[i] = current_right_max;
            current_right_max = max(current_right_max, height[i]);
        }

        int water = 0 ;
        for(int middle = 1; middle < height.size()-1; ++middle){
            const int hight_min = min(leftMax[middle], rightMax[middle]);
            water+=max( hight_min - height[middle], 0);
        }

        return water;
    }
};
