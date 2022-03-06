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
    ListNode* removeElements(ListNode* head, int val) 
    {
        if (head==NULL)
            return head;
        ListNode* past = new ListNode(-1), *current = head, *nextOne = head->next;
        ListNode* newHead = past;
        newHead->next = head;   // sentinel
        int flag = 1;
        
        while(true)
        {
            flag = 1;
            if (current->val == val)
            {
                past->next = nextOne;
                flag = 0;
            }
            if (flag)
                past = current;
            current = nextOne;
            if (current == NULL)
                break;
            nextOne = current->next;
        }
        return newHead->next;
    }
};