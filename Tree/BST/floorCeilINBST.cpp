/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 int findCeil(TreeNode* root, int x){
    if(!root) return -1;
    
    if(root->val == x) 
        return root->val;
        
    if(root->val < x) 
        return findCeil(root->right,x);
    
    int ceils =  findCeil(root->left,x);
    
    return (ceils>=x)?ceils:root->val;
}
int findFloor(TreeNode* root, int x){
    if(!root) return INT_MAX;
    
    if(root->val == x) 
        return root->val;
    
    if(root->val > x)
        return findFloor(root->left,x);
    
    int flor = findFloor(root->right, x);
    return (flor<=x)?flor:root->val;
}
vector<vector<int> > Solution::solve(TreeNode* A, vector<int> &B) {
    int n = B.size();
    vector<vector<int>> ans;
    
    for(int i=0;i<n;i++){
        int fl = findFloor(A,B[i]);
        if(fl==INT_MAX) fl = -1;
        int cl = findCeil(A, B[i]);
        ans.push_back({fl,cl});
    }
    return ans;
}
