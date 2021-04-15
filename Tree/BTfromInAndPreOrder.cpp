// Link : https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
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
    TreeNode* buildHelper(vector<int>& preorder, vector<int>& inorder, int ins, int ine, int pres, int pree){
        if(ins > ine) return NULL;
        
        TreeNode* root = new TreeNode(preorder[pres]);
        int i;
        for(i=ins; i<ine; i++){
            if(inorder[i] == preorder[pres])
                break;
        }
        root->left = buildHelper(preorder, inorder, ins, i-1, pres+1, pres+i-ins);
        root->right = buildHelper(preorder, inorder, i+1,ine,pres+i-ins+1, pree); 
        
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        int n = preorder.size(), m = inorder.size();
        TreeNode* root = buildHelper(preorder, inorder, 0, n-1, 0, m-1);
        
        return root;
    }
};
