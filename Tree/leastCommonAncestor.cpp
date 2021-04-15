/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root ) return NULL;
        
        if(root == p || root==q) return root;
        
        TreeNode* leftSide = lowestCommonAncestor(root->left,p,q);
        TreeNode* rightSide = lowestCommonAncestor(root->right,p,q);
        
        if(leftSide && rightSide) return root;
        
        if(leftSide) return leftSide;
        return rightSide;
        
    }
};
