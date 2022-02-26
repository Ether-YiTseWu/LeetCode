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
    ListNode* rotateRight(ListNode* head, int k) 
    {
        if (head == NULL || head->next == NULL || k == 0)
            return head;
        int times = k%getLength(head);
        ListNode *p, *lastOne = head; // lastOne == head for times == 0
        for (int i = 0 ; i < times ; i++)
        {
            if (i == 0)
                p = head;
            else
            {
                p = lastOne;
                head = lastOne; // lastOne would be the head while the end of the for loop
            }
            while(p->next->next!=NULL)
                p = p->next; 
            lastOne = p->next;
            p->next = NULL;
            lastOne->next = head;
        }
        return lastOne;
    }
    
    int getLength(ListNode* head)
    {
        ListNode *p = head;
        int count = 0;
        while(p!=NULL)
        {
            p = p -> next;
            count ++;
        }
        return count;
    }
};