// Link : https://leetcode.com/problems/recover-binary-search-tree/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* first;
    TreeNode* previous;
    TreeNode* middle;
    TreeNode* last; 

    void inorder(TreeNode* root) {
        if(root == NULL) return; 
        
        inorder(root->left);
        
        if (previous != NULL && (root->val < previous->val))
        {
           
            // If this is first violation, mark these two nodes as
            // 'first' and 'middle'
            if ( first == NULL )
            {
                first = previous;
                middle = root;
            }
 
            // If this is second violation, mark this node as last
            else
                last = root;
        }
 
        // Mark this node as previous
        previous = root;
        inorder(root->right); 
    } 
vector<int> Solution::recoverTree(TreeNode* A) {
    first = middle = last = NULL; 
        previous = new TreeNode(INT_MIN); 
        inorder(A);
        vector<int> ans(2);
        if(first && last) { ans[0]=first->val;ans[1]= last->val;}
        else if(first && middle) {ans[0]=first->val, ans[1]=middle->val;}

    sort(ans.begin(),ans.end());
    return ans;
}
