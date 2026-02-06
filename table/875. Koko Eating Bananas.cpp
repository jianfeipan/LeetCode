/*
You are given an integer array piles where piles[i] is the number of bananas in the ith pile. You are also given an integer h, which represents the number of hours you have to eat all the bananas.

You may decide your bananas-per-hour eating rate of k. Each hour, you may choose a pile of bananas and eats k bananas from that pile. If the pile has less than k bananas, you may finish eating the pile but you can not eat from another pile in the same hour.

Return the minimum integer k such that you can eat all the bananas within h hours.

Example 1:

Input: piles = [1,4,3,2], h = 9

Output: 2
Explanation: With an eating rate of 2, you can eat the bananas in 6 hours. With an eating rate of 1, you would need 10 hours to eat all the bananas (which exceeds h=9), thus the minimum eating rate is 2.

Example 2:

Input: piles = [25,10,23,4], h = 4

Output: 25
Constraints:

1 <= piles.length <= 1,000
piles.length <= h <= 1,000,000
1 <= piles[i] <= 1,000,000,000

*/

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        //[1,4,3,2], h = 9
        // BF: start from 1, simulate what happens
        // improve1: speed >= theoritical min speed: sum{piles} / h
        // improve2: no need to simulate, every pile time is just a division
        int sum = 0;
        int maxPile = 0;
        for(int pile:piles) {
            sum+=pile;
            maxPile = max(maxPile, pile);
        }
        int minSpeed = max(sum/h,1);
        int maxSpeed = maxPile;
        int speed = maxSpeed;
        while(minSpeed<=maxSpeed){
            const int middleSpeed = (minSpeed+maxSpeed)/2;
            int timeUsed = 0;
            for(int pile:piles) {
                timeUsed+=ceil(static_cast<double>(pile) / middleSpeed);
            }
            if(timeUsed<=h){//from large going to small, and find the last right boundry who satisfy the condition
                speed = middleSpeed;
                maxSpeed = middleSpeed-1;
            }else{
                minSpeed = middleSpeed+1;
            }
        }
        
        
        return speed;
    }
};
