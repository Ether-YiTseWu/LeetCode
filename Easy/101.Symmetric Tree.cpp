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
    bool answer = 1;
    bool isSymmetric(TreeNode* root) 
    {
        check(root->left, root->right);
        return answer;
    }
    void check(TreeNode* p, TreeNode* q)
    {
        // CASE01 : One node is null and the other node isn't null
        if ((p != NULL && q == NULL) || (p == NULL && q != NULL))
            answer = 0;
        if (p == NULL || q == NULL)
            return;
        // CASE02 : Two nodes aren't null
        if (p->val != q->val)
            answer = 0;
        // Symmetric Search
        check(p->left, q->right);
        check(p->right, q->left);
    }
};