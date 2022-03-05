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
        if (head == NULL || head->next==NULL)
            return head;
        ListNode *last = NULL, *current = head, *nextOne = head->next;
        ListNode *newHead = new ListNode(-101);
        int flag, returnFlag = 0;
        
        while(nextOne!=NULL)
        {
            flag = 0;
            while (nextOne!=NULL && current->val == nextOne->val)
            {
                flag = 1;
                nextOne = nextOne->next;
            }
            if (flag)
            {
                if (last==NULL)
                {
                    last = newHead; 
                    returnFlag = 1;
                }
                last->next = nextOne;
                current = nextOne;
                if (nextOne != NULL)
                    nextOne = current->next;
                continue;
            }
            last = current;
            current = current -> next;
            nextOne = current->next;
        }
        if (returnFlag)
            return newHead->next;
        return head;
    }
};