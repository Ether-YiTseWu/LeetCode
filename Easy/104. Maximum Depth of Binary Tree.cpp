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
    int maxDepth(TreeNode* root) 
    {
        return height(root);
    }
    
    int height(TreeNode* node) //https://www.geeksforgeeks.org/write-a-c-program-to-find-the-maximum-depth-or-height-of-a-tree/
    {
        if (node == NULL)
            return 0;
        else 
        {
            // compute the height of each subtree
            int lheight = height(node->left);
            int rheight = height(node->right);
 
            // use the larger one
            if (lheight >= rheight)
                return (lheight + 1);
            else
                return (rheight + 1);
        }
    }
};