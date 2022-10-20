/*21. Merge Two Sorted List
You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists in a one sorted list. The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list.
*/

//Oct 20, 2022
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *p3, *ans;
        p3 = new ListNode();
        ans = p3;
        while (list1 && list2)
        {
            if(list1->val > list2->val)
            {
                ans->next= list2;
                list2 = list2->next;
            }
            else
            {
                ans->next= list1;
                list1 = list1->next;
            }
            ans = ans->next;
        }
        
        //move the rest
        if(list1)
            ans ->next= list1;
        if(list2)
            ans ->next= list2;
        
        return p3->next;
    }
};