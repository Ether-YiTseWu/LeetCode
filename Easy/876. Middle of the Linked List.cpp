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
    ListNode* middleNode(ListNode* head) 
    {
        ListNode* p = head;
        int length = getLength(head), middle = 0;
        if(length % 2 == 1)
        {
            while(p!=NULL)
            {
                middle++;
                if (middle == (length+1)/2)
                    return p;
                p = p->next;
            }
        }
        else
        {
            while(p!=NULL)
            {
                middle++;
                if (middle == length/2+1)
                    return p;
                p = p->next;
            }
        }
        return head;
    }
    int getLength(ListNode* p)
    {
        int count = 0;
        while(p!=NULL)
        {
            count++;
            p = p->next;
        }
        return count;
    }
    
};