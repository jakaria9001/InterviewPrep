// Link : https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/

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
    int maxLevelSum(TreeNode* root) {
        if(root == NULL) return 0; //base case
        int result = root->val; // initialize result
        int level = 1, ans = 1;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            
            int count = q.size();
            
            int sum = 0;
            
            while(count--){
                TreeNode* temp = q.front();
                q.pop();
                
                sum+= temp->val;
                
                if(temp->left!=NULL) q.push(temp->left);
                if(temp->right!=NULL) q.push(temp->right);
            }
            // result = max(sum, result);
            if(sum>result){
                ans = level;
                result = sum;
            }
            level++;
        }
        return ans;    
    }
    
};
