// Link: https://leetcode.com/problems/equal-tree-partition/

/** 
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

stack<int> st;


int solve1(TreeNode* root){
    if(!root) return 0;

    int lsum = solve1(root->left);
    int rsum = solve1(root->right);

    int curr = root->val + lsum + rsum;

    st.push(curr);

    return curr;
}
int Solution::solve(TreeNode* A) {
    if(!A) return 0;
    // st.clear();
    while(!st.empty()) st.pop();
    solve1(A);

    int tsum = st.top();
    st.pop();

    while (!st.empty()) {
         int x = st.top();
         st.pop();
         int y = tsum - x;
         if (x == y)
            return true;
      }
    return false;

}
