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
//Link: https://leetcode.com/problems/path-sum/
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        bool ans = false;
        
        int cd = targetSum - root->val;
        
        if(!cd && root->left, root->right) 
            return true;
        if(root->left) ans = ans || hasPathSum(root->left, cd);
        if(root->right) ans = ans|| hasPathSum(root->right, cd);
        
        return ans;
    }
};
