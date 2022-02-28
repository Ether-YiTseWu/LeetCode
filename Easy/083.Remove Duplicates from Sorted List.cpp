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
    ListNode* deleteDuplicates(ListNode* head) 
    {
        int flag;
        ListNode *p = head, *q, *answer = new ListNode(-101);
        while(p!=NULL)
        {
            ListNode *newNode = new ListNode(p->val);
            q = answer, flag = 1;
            while(q->next!=NULL)
            {
                if (q->val == p->val)
                    flag = 0;
                q = q->next;
            }
            // Need to check one more time because p is the last listNode of answer(variable name) now
            if (q->val == p->val)
                flag = 0;
            if (flag)
                q->next = newNode;
            p = p -> next;
        }
        return answer->next;
    }
};