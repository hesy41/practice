/*160. Intersection of Two Linked Lists
  Given the heads of two singly linked-lists headA and headB, return the node at which the two lists intersect. 
  If the two linked lists have no intersection at all, return null.*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* pa = headA;
        ListNode* pb = headB;
        
        if(! headA || ! headB)
            return NULL;
        
        while(pa != NULL && pb != NULL && pa != pb)
        {
            pa = pa->next;
            pb = pb->next;
            
            if(pa == pb)
                return pa;
            if(!pa)
                pa = headA;
            if(!pb)
                pb = headB;
        }
        //returen holder
        return pa;
    }
};