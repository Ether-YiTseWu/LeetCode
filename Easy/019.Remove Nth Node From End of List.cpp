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
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        ListNode *p = head;
        int length = 1, N;
        
        // Get Nth from the begin of list
        while(p->next!=NULL)
        {
            length++;
            p = p->next;
        }
        N = length - n + 1;
        
        // Deal with the exception condition 
        if (length == 1)
            return NULL;
        if (N == 1)
            return head->next;
        
        // Find the node and replace
        p = head;
        while(N--)
        {
            if (N == 1)
            {
                // Remove
                p->next = p->next->next;
                break;
            }
            p = p->next;
        }
        return head;
    }
};