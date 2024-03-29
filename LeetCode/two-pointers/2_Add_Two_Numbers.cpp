/*2. Add Two Numbers
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.*/

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode prehead;
        ListNode *p = &prehead;
        int extra = 0;
        
        while(extra || l1 || l2)
        {
            int sum = (l1? l1->val : 0) + (l2? l2->val :0)+extra;
            extra = sum/10;
            p->next = new ListNode(sum % 10);
            p = p->next;
            
            //move the pointer for l1 and l2
            l1 = (l1? l1->next : l1);
            l2 = (l2? l2->next : l2);
        }
        return prehead.next;
    }
};