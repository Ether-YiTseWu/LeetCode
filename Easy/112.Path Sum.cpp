/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int target, sum = 0;
    bool answer = false;
    bool hasPathSum(TreeNode* root, int targetSum) 
    {
        if (root==NULL)
            return false;
        target = targetSum;
        check(root, sum);
        return answer;
    }
    
    // The key is that bring int variable into recursuve function, and use four if/else condition to compute
    void check(TreeNode* p, int s)
    {   
        if (p != NULL)
        {
            if (p->left==NULL && p->right==NULL)
            {   
                s += p->val;
                if (target == s)
                    answer = true;
                return;
            }
            else if (p->left!=NULL && p->right==NULL)
            {
                s += p->val;
                check(p->left, s);
            }
            else if (p->left==NULL && p->right!=NULL)
            {
                s += p->val;
                check(p->right, s);
            }
            else
            {
                s += p->val;
                check(p->left, s);
                check(p->right, s);
            }
        }
        else
            return;
    }
};