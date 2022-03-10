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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        ListNode* newHead_L1 = l1, *newHead_L2 = l2, *answer = new ListNode(0);
        int length1 = getLength(l1), length2 = getLength(l2), value, temp = 0;
        if (length1 >= length2)
        {
            while(newHead_L1 != NULL)
            { 
                if (newHead_L2 != NULL)
                {
                    value = newHead_L1->val + newHead_L2->val;
                    value += temp;
                    newHead_L2 = newHead_L2->next;
                }
                else
                    value = newHead_L1->val + temp;
                if (value >= 10)
                {
                    temp = 1;
                    value %= 10;
                }
                else
                    temp = 0;
                // Push Back 
                ListNode* newNode = new ListNode(value), *p = answer;
                while(p->next!=NULL)
                    p = p->next;
                p->next = newNode;
                newHead_L1 = newHead_L1->next;
            }
        }
        else
        {
            while(newHead_L2 != NULL)
            { 
                if (newHead_L1 != NULL)
                {
                    value = newHead_L1->val + newHead_L2->val;
                    value += temp;
                    newHead_L1 = newHead_L1->next;
                }
                else
                    value = newHead_L2->val + temp;
                if (value >= 10)
                {
                    temp = 1;
                    value %= 10;
                }
                else
                    temp = 0;
                // Push Back 
                ListNode* newNode = new ListNode(value), *p = answer;
                while(p->next!=NULL)
                    p = p->next;
                p->next = newNode;
                newHead_L2 = newHead_L2->next;
            }
        }
        
        if (temp == 1)
        {
            ListNode* newNode = new ListNode(1), *p = answer;
            while(p->next!=NULL)
                p = p->next;
            p->next = newNode;
        }
        
        return answer->next;
    }
    
    int getLength(ListNode* head)
    {
        int answer = 0;
        while(head!=NULL)
        {
            answer ++;
            head = head->next;
        }
        return answer;
    }
};