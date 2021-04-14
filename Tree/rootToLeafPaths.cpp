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
// Link : https://leetcode.com/problems/binary-tree-paths/submissions/
class Solution {
public:
    vector<string> ans;
    void preorderPaths(TreeNode* root, string curr){
         if(!root) {
                return;
         }
        
        
         if(curr=="") curr = to_string(root->val);
         else curr = curr+"->"+to_string(root->val);
        
         if(!root->left && !root->right) {
                ans.push_back(curr);
                curr = "";
         }
         preorderPaths(root->left,curr);
         preorderPaths(root->right,curr);
        
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        // vector<string> ans;
        if(!root) return ans;
        string curr = "";
        preorderPaths(root, curr);
        
        return ans;
    }
};
