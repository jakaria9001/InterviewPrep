// Link : https://leetcode.com/problems/balance-a-binary-search-tree/
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
    void inorder(TreeNode* root, vector<int>&ino){
        if(!root) return;
        
        inorder(root->left, ino);
        ino.push_back(root->val);
        inorder(root->right, ino);
        
    }
    TreeNode* createBST(vector<int>&ino, int st, int en){
        if(st>en) return NULL;
        int mid = (st+en)/2;
        TreeNode* nn = new TreeNode(ino[mid]);
        
        nn->left = createBST(ino, st, mid-1);
        nn->right = createBST(ino,mid+1,en);
        
        return nn;
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> ino;
        inorder(root, ino);
        
        return createBST(ino, 0 , ino.size()-1);
    }
};
