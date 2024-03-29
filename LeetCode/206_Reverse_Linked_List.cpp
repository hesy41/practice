/*Given the head of a singly linked list, reverse the list, and return the reversed list.
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
    ListNode* reverseList(ListNode* head) {
        //no need to create a new linked list
        //simply reverse the pointer would be fine
        ListNode *prev = NULL, *next;
        while(head)
        {
            next = head ->next;
            head -> next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
};