/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// Is two tree identical : using preorder traversal 
int Solution::isSameTree(TreeNode* A, TreeNode* B) {
    if(!A && B) return 0;
    if(A && !B) return 0;
    if(!A && !B) return 1;
    
    int curr = (A->val == B->val);  
    curr = (curr && isSameTree(A->left,B->left));
    curr = (curr && isSameTree(A->right,B->right));
    
    return curr;
}
