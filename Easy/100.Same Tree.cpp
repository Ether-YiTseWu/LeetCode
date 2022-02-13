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
    int count = 0, length = 0;
    bool isSameTree(TreeNode* p, TreeNode* q) 
    {
        checkVal(p, q);
        if (count == length)
            return 1;
        return 0;
    }
    // Recursion, check the length and value of the two nodes are same or not
    void checkVal(TreeNode* p, TreeNode* q)
    {
        if(p == NULL && q == NULL)
            return;
        else if (p == NULL || q == NULL)
        {
            length ++;
            return;
        }
        length ++;
        if (p->val == q->val)
            count++;
        checkVal(p->left, q->left);
        checkVal(p->right, q->right);
    }
};