/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
int Solution::solve(TreeNode* A) {

    int osum = 0, esum = 0, level = 0;
    if(!A) return 0;
    
    queue<TreeNode*> q;
    q.push(A);
    while(!q.empty()){
        int n = q.size();
        for(int i=0;i<n;i++){
            TreeNode* temp = q.front();
            q.pop();
            
            if(level%2==0) esum+=temp->val;
            else osum += temp->val;
            
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
            
        }
    
        level++;
    }
    return (esum-osum);
    
}
