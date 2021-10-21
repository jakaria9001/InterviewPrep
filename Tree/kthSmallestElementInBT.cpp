// Link: https://www.interviewbit.com/problems/kth-smallest-element-in-tree/
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

 vector<int> arr;

void inorder(TreeNode *root){
    if(!root) return ;

    inorder(root->left);
    arr.push_back(root->val);
    inorder(root->right);
}

int Solution::kthsmallest(TreeNode* A, int B) {
     arr.clear();
    inorder(A);

    sort(arr.begin(), arr.end());
    return arr[B-1];
}


