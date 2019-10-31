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
    ListNode* reverseList(ListNode* head) {
        ListNode* p = head;
        ListNode* prev = NULL;
        ListNode* current = NULL;
        while(p != NULL)
        {
            prev = current;
            current = p;
            p = p->next;
            current -> next = prev;
        }
        return current;
    }
};
