// Link: https://www.geeksforgeeks.org/check-if-a-given-binary-tree-is-sumtree/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
pair<bool, int> postorder(TreeNode* root, int sum){
    if(!root) return {true,0};

    pair<bool, int> lside = postorder(root->left,sum);
    pair<bool, int> rside = postorder(root->right,sum);

    if(!lside.first || !rside.first) return {false, 0};

    if(!root->left && !root->right) return {true, root->val};

    if(lside.second + rside.second == root->val){
        return {true, lside.second + rside.second + root->val};
    }
    return {false, 0};
}

int Solution::solve(TreeNode* A) {
    if(!A) return 1;
    int sum = 0;
    pair<bool, int> ans = postorder(A, sum);    
    return ans.first;
}
