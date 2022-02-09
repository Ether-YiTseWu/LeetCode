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
    int getEle(ListNode* list, int index)
    {
        int count = 0;
        ListNode* p = list;
        while(p->next != NULL)
        {
            if(count == index)
                return p->val;
            p = p->next;
            count++;
        }
        return p->val;
    }
    
    ListNode* getAddr(ListNode* list, int index)
    {
        int count = 0;
        ListNode* p = list;
        while(p->next != NULL)
        {
            if(count == index)
                return p;
            p = p->next;
            count++;
        }
        return p;
    }
    
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) 
    {
        if (list1 == NULL)
            return list2;
        if (list2 == NULL)
            return list1;
        
        // Find the last address of list1
        ListNode* q = list1;
        while(q -> next != NULL)
            q = q -> next;
        
        // Append list2 into list1
        ListNode* p = list2;
        while(p -> next != NULL)
        {
            ListNode *n = new ListNode(p->val);
            q -> next = n;
            q = n;
            p = p->next;
        }
        ListNode *n = new ListNode(p->val);
        q -> next = n;
        
        // Get length
        int length = 0;
        ListNode* r = list1;
        while(r->next != NULL)
        {
            length ++;
            r = r->next;
        }
        length++;
        
        // Bubble Sort
        for (int i = 0 ; i < length ; i++)
        {
            for (int j = i + 1 ; j < length ; j++)
            {
                if (getEle(list1, j) < getEle(list1, i))
                {
                    int temp = getEle(list1, j);
                    getAddr(list1, j)->val = getEle(list1, i);
                    getAddr(list1, i)->val = temp;
                }
            }
        }
        
        return list1;
    }
};