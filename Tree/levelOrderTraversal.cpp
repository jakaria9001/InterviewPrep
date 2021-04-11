/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// Level order traversal : 
void level(TreeNode* root, vector<vector<int>>& ans){
    
    if(!root) return;
    
    queue<TreeNode*> q;
    q.push(root);
    
    while(!q.empty()){
        
        vector<int> tt;
        int n = q.size();
        for(int i=0;i<n;i++){
            TreeNode* temp = q.front();
            q.pop();
            tt.push_back(temp->val);
            
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
        ans.push_back(tt);
        
    }
    
}

vector<vector<int> > Solution::levelOrder(TreeNode* A) {
    vector<vector<int>> ans;
    level(A, ans);
    
    return ans;
    
}
