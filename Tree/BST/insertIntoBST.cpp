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
// Link : https://leetcode.com/problems/insert-into-a-binary-search-tree/
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root){
            TreeNode* nn = new TreeNode(val);
            return nn;
        }
        
        if(root->val < val)
            root->right = insertIntoBST(root->right, val);
        else root->left = insertIntoBST(root->left, val);
        
        return root;
    }
};
