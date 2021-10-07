/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int ans = 0;

void fun(TreeNode* root, int b, int c){
    if(!root) return;
    
    if(root->val >= b && root->val <= c) ans++;
    
    fun(root->right, b, c);
    fun(root->left, b,c);
    
}
int solve(TreeNode* A, int B, int C) {
    ans = 0;
    fun(A,B,C);
    return ans;
}
