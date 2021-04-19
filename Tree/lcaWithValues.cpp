/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
bool find(TreeNode* root, int x){
    if(!root) return false;
    if(root->val == x || find(root->left,x) || find(root->right,x))
        return true;
    return false;
} 
TreeNode* lcaU(TreeNode* A, int B, int C, bool &v1, bool &v2){
    
    if(!A) return NULL;
    
    if(A->val == B){
        v1 = true;
        return A;
    } 
    if(A->val == C){ 
        v2 = true;
        return A;
    }
    
    TreeNode* leftLCA = lcaU(A->left, B, C,v1,v2);
    TreeNode* rightLCA = lcaU(A->right, B, C,v1,v2);
    
    if(leftLCA && rightLCA) return A;
    
    if(leftLCA) return leftLCA;
    return rightLCA;
}
int Solution::lca(TreeNode* A, int B, int C) {
    
    bool v1 = false, v2 = false;
    TreeNode* ll = lcaU(A,B,C,v1,v2);
    
    if(v1&&v2 || v1&&find(ll,C) || v2&&find(ll,B)) return ll->val;
    return -1;
}
