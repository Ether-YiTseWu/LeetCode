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
    ListNode* mergeNodes(ListNode* head) 
    {
        ListNode *answer = new ListNode(), *q = new ListNode(); 
        q = answer;
        int count = -1, sum = 0; 
        while(head!=NULL)
        {
            if (head->val==0)
            {
                count++;
                // First Node
                if(count == 1)
                {
                    answer->val = sum;
                    sum = 0;
                }
                // Add node into the final address
                else if(count > 1)
                {
                    ListNode*newNode = new ListNode(sum);
                    q->next = newNode;
                    q = q->next;
                    sum = 0;
                }
            }
            else
                sum+=head->val;
            head = head->next;
        }
        return answer;
    }
};