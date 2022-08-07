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
    int ansLen = 0;
    vector<TreeNode*> t;
    vector<string> binaryTreePaths(TreeNode* root) 
    {
        vector<string> ans;
        countLen(root);
        while(ansLen)
        {
            TreeNode *p = root, *last;
            string s = "";
            while(!(p -> left == NULL && p -> right == NULL))
            {
                s += (to_string(p->val) + "->");
                last = p;
                if (p -> left != NULL && p -> right == NULL)
                    p = p -> left;
                else if (p -> left == NULL && p -> right != NULL)
                    p = p -> right;
                else
                    p = p -> left;
            }
            s += to_string(p->val);
            if (last != NULL)
            {
                if (last -> left != NULL)
                    last->left = NULL;
                else
                    last->right = NULL;   
            }
            for (int i = 0 ; i < t.size() ; i++)
            {
                if (t[i] == p)
                {
                    ans.push_back(s);
                    ansLen -= 1;
                    i = t.size();
                }
            }
        }
        return ans;
    }
    void countLen(TreeNode* p)
    {
        if (p -> left == NULL && p -> right == NULL)
        {
            t.push_back(p);
            ansLen += 1;
            return;
        }
        else if (p -> left != NULL && p -> right == NULL)
            countLen(p -> left);
        else if (p -> left == NULL && p -> right != NULL)
            countLen(p -> right);
        else
        {
            countLen(p -> left);
            countLen(p -> right);
        }
    }
};