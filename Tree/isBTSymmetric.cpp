//Link :  https://leetcode.com/problems/symmetric-tree/

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
    bool ulta(TreeNode* lef, TreeNode* rgt){
         // if(!root) return NULL;

        if(!lef && !rgt) return true;
        if((!lef && rgt)||(lef && !rgt)) return false;
        
        if(lef->val==rgt->val)
            return (ulta(lef->left, rgt->right) && ulta(lef->right, rgt->left));
        return false;
    }
    bool isSymmetric(TreeNode* A) {
        
        return ulta(A->left, A->right);
    }
};
