/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void inorder(TreeNode *root, vector<int> &ans){
    if(!root) return;
    
    inorder(root->left, ans);
    ans.push_back(root->val);
    inorder(root->right, ans);
    
}
vector<int> Solution::inorderTraversal(TreeNode* A) {
    vector<int> ans;
    inorder(A, ans);
    return ans;
}
