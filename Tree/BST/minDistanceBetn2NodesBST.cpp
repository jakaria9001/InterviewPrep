/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

int distanceFromLCA(TreeNode* root, int x){
    
    if(root->val == x) return 0;
    
    if(root->val>x)
        return 1+distanceFromLCA(root->left, x);
    return 1+distanceFromLCA(root->right, x);
}
int distanceBtnBST(TreeNode* root, int x, int y){
    if(!root) return 0;
    
    if(root->val > x && root->val > y)
        return distanceBtnBST(root->left, x, y);
    if(root->val < x && root->val < y)
        return distanceBtnBST(root->right, x, y);
    if(root->val >= x && root->val <= y)
        return distanceFromLCA(root, x) + distanceFromLCA(root, y);;
        // return distancBtnBST(root->left, x, y);
        
}
int Solution::solve(TreeNode* A, int B, int C) {
    if(B>C) 
        swap(B,C);
    return distanceBtnBST(A, B, C);
}
