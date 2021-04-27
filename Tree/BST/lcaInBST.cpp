// Link : https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return NULL;
        
        int val = root->val, x = p->val, y = q->val;
        if(val>x && val>y)
            return lowestCommonAncestor(root->left, p, q);
        if(val<x && val<y)
            return lowestCommonAncestor(root->right, p , q);
        return root;
    }
};
