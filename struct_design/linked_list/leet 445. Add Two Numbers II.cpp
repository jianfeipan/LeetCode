/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {

/*
You are given two non-empty linked lists representing two non-negative integers. The most significant digit comes first and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

 Input: l1 = [7,2,4,3], l2 = [5,6,4]
Output: [7,8,0,7]
Example 2:

Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [8,0,7]
Example 3:

Input: l1 = [0], l2 = [0]
Output: [0]



*/
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        ListNode* totalSum = new ListNode();
     
        size_t len1 = count(l1);
        size_t len2 = count(l2);
        
        int diff = 0;
        
        ListNode* shortNum = l1;
        ListNode* longerNum = l2;
        
        if(len1 > len2)
        {
            longerNum = l1;
            shortNum = l2;
            diff = len1 - len2;
        }
        else
        {
            diff = len2 - len1;
        }
        
        //rather than move the pointer to long list, easy way is to add 0s in front of short list
        
        ListNode* filledShort = fillZeroOnLeft(shortNum, diff);
        
        int carry = 0;
        auto * rightSum = addTwoNumbersWithSameLen(filledShort, longerNum, carry);
        auto current = totalSum;
        if(carry)
        { 
            current->next = new ListNode(carry);
            current = current->next;
        }
        
        
        current->next = rightSum;
            
        return totalSum->next;
    }
private:
    ListNode* addTwoNumbersWithSameLen(ListNode* l1, ListNode* l2, int & carry) 
    {
        if(!l1 && !l2) return nullptr;
        
        int carryFromRight = 0;
        auto rightSum = addTwoNumbersWithSameLen(l1->next, l2->next, carryFromRight);
        
        const int sum = l1->val + l2->val + carryFromRight;
        
        carry = sum/10;
        return new ListNode(sum%10, rightSum);
    }
    
    size_t count(ListNode* node)
    {
        size_t size= 0;
        while(node)
        {
            size++;
            node = node->next;
        }
        return size;
    }
    
    ListNode * fillZeroOnLeft(ListNode* shortNum, int n)
    {
        if(n==0) return shortNum;
        return new ListNode(0, fillZeroOnLeft(shortNum, n-1));
    }

};
