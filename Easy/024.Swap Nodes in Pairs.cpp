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
    ListNode* swapPairs(ListNode* head) 
    {
        if (head==NULL)
            return head;
        int count = 0;
        ListNode* p = head;
        // every two nodes, swap one time
        while(p!=NULL)
        {
            count ++;
            if (count % 2 == 1 and p->next!=NULL)
                swap(p);
            p = p->next;
        }
        return head;
    }
    void swap(ListNode* p)
    {
        int temp = p->next->val;
        p->next->val = p->val;
        p->val = temp;
    }
};