/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// link : https://leetcode.com/problems/find-a-corresponding-node-of-a-binary-tree-in-a-clone-of-that-tree/submissions/
class Solution {
public:
    TreeNode* temp;
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        if(original == NULL) return NULL;
        
        if(original-> val == target->val) temp = cloned;
    
        getTargetCopy(original->left, cloned->left, target);
        getTargetCopy(original->right, cloned->right, target);
        
        return temp;
    }
    
};
