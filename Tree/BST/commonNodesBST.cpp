/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
const long mod = 1e9+7;
bool searchBST(int x, TreeNode* root){
    if(!root) return false;
    if(root->val == x) return true;
    if(root->val > x) return searchBST(x, root->left);
    return searchBST(x, root->right);
}
void inorder(TreeNode* root,TreeNode* B, long& ans){
    if(!root) return;
    
    if(searchBST(root->val,B))
        ans = (ans+root->val)%mod;
    inorder(root->left, B, ans);
    inorder(root->right, B, ans);
    
}
int Solution::solve(TreeNode* A, TreeNode* B) {
    long ans = 0;
    inorder(A,B,ans);
    return ans%mod;
}
