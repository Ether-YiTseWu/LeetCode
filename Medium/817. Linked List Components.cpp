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
    int numComponents(ListNode* head, vector<int>& nums) 
    {
        // Set up variables
        bool flag;
        int answer = 0;
        vector<int> reOrderList;
        ListNode *p = head;
        reOrderList.push_back(-1);
        
        // Get reOrderList
        while(p != NULL)
        {
            flag = 0;
            for (int i = 0 ; i < nums.size() ; i++)
            {
                if (nums[i] == p->val)
                {
                    reOrderList.push_back(p->val);
                    flag = 1;
                    break;
                }
            }
            if (!flag)
                reOrderList.push_back(-1);
            p = p -> next;
        }
        reOrderList.push_back(-1);
        
        // Count the independent block mount (notice the reapting -1)
        for (int i = 0 ; i < reOrderList.size() ; i++)
        {
            flag = 0;
            while (reOrderList[i] == -1)
            {
                if (!flag)
                    answer ++;
                flag = 1;
                i += 1;
            }
        }
        
        return answer-1;
    }
};