/*
You are given two non-empty linked lists, l1 and l2, where each represents a non-negative integer.

The digits are stored in reverse order, e.g. the number 321 is represented as 1 -> 2 -> 3 -> in the linked list.

Each of the nodes contains a single digit. You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Return the sum of the two numbers as a linked list.

Input: l1 = [1,2,3], l2 = [4,5,6]

Output: [5,7,9]

Explanation: 321 + 654 = 975.
Example 2:

Input: l1 = [9], l2 = [9]

Output: [8,1]
Constraints:

1 <= l1.length, l2.length <= 100.
0 <= Node.val <= 9



*/



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
public:
    /*
    facts:
        1.linked list is from smaller digital
        2.non-negative numbers
    idea: 
        two pointers
        sum nodes, if >10, use a flag to note there is a 10
        then next, util both list  null 

    */


    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        ListNode beforeFirst;
        auto n1 = l1;
        auto n2 = l2;
        int carry = 0;
        auto prev = &beforeFirst;
        while(n1 || n2)
        {
            int sum = carry;
            if(n1)
            {
                sum+=n1->val;
                n1 = n1->next;
            }
            if(n2){
                sum+=n2->val;
                n2 = n2->next;
            } 

            if(sum>=10) 
            {
                carry = 1;
                sum-=10;
            }
            else 
            {
                carry = 0;
            }
            prev->next = new ListNode(sum);
            prev = prev->next;
        }

        if(carry)
        {
            prev->next = new ListNode(1);
        }

        return beforeFirst.next;
    }
};
