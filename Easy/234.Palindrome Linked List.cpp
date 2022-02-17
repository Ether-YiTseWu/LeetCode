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
    bool answer = false;
    bool isPalindrome(ListNode* head) 
    {
        // Record value array
        int *value = new int[getLength(head)], count = 0;
        ListNode* p = head;
        while(p->next!=NULL)
        {
            value[count] = p->val;
            p = p->next;
            count++;
        }
        value[count] = p->val;
        
        // Reverse
        ListNode *current;
        ListNode *past, *n;
        current = head;
        past = n = NULL;
        while(current!=NULL)
        {
            n = current->next;
            current->next = past;
            
            past = current;
            current = n;
        }
        head = past;
        
        // Check value
        p = head;
        count = 0;
        while(p->next!=NULL)
        {
            if (value[count]==p->val)
                count++;
            p = p->next;
        }
        if (value[count]==p->val)
            count++;
        
        // Check count length == getLength(head)?
        if (count == getLength(head))
            answer = true;
        return answer;
        
    }
    int getLength(ListNode* p)
    {
        int l = 1;
        while(p->next)
        {
            l++;
            p = p->next;
        }
        return l;
    }
};