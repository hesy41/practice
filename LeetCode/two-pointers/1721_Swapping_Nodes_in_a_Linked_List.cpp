/*1721. Swapping Nodes in a Linked List
You are given the head of a linked list, and an integer k.
Return the head of the linked list after swapping the values of the kth node from the beginning and the kth node from the end (the list is 1-indexed).*/

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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* p1=head, *p2=head, *kth=NULL;
        while(--k)
            p1 = p1->next;
        
        kth = p1;
        p1= p1->next;
        
        while(p1)
        {
            p2 = p2->next;
            p1 = p1->next;
        }
        swap(p2->val, kth->val);
        return head;
    }
};