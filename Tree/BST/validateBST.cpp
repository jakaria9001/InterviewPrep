// Link : https://leetcode.com/problems/validate-binary-search-tree/submissions/
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
class Solution {
public:
    
    bool isBST(TreeNode* root, TreeNode* low, TreeNode* high){
    
        if(!root) return true;

        if( (low && root->val<=low->val) || (high && root->val>=high->val)) 
            return false;
        
        bool isLeft = isBST(root->left, low, root );
        bool isRight = isBST(root->right, root, high);

        return (isLeft && isRight);
    }

    bool isValidBST(TreeNode* A) {
        if(!A) return 1;
    
        TreeNode *low = NULL, *high = NULL;

        return isBST(A, low, high);
    }
};
