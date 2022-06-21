/*19. Remove Nth Node From End of List
  Given the head of a linked list, remove the nth node from the end of the list and return its head.*/

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head)
            return NULL;
        else if(head->next==NULL && n==1)
            return NULL;
            
        ListNode* first=head;
        ListNode* last=head;
        while(n>0)
        {
            first=first->next;
            n--;
        }
        if(!first)
            return head->next;
        while(first->next)
        {
            first=first->next;
            last=last->next;
        }
        //last=last->next;
        //when out of loop  last->next is the one to delete
        ListNode* temp=last->next;
        last->next=temp->next;
        delete temp;
        
        return head;
    }
};