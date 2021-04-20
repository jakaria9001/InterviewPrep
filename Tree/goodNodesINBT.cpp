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

// Link : https://leetcode.com/problems/count-good-nodes-in-binary-tree/
class Solution {
public:
    void helper(TreeNode* root, int mxanc, int& ans){
        if(!root) return;
        
        if(root->val >= mxanc) ++ans;
        
        helper(root->left, max(mxanc, root->val), ans);
        helper(root->right, max(mxanc, root->val), ans);
        
    }
    int goodNodes(TreeNode* root) {
        int mxanc = INT_MIN, ans = 0;
        
        helper(root, mxanc, ans);
        
        return ans;
    }
};
