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
// Link: https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/
class Solution {
public:
//     vector<vector<int>> verticalTraversal(TreeNode* root) {
//         vector<vector<int>> ans;
//         if(!root) return ans;
//         queue<pair<int, TreeNode*>> q;
//         q.push(make_pair(0,root));
//         map<int, vector<int>> mp;
        
//         while(!q.empty()){
//             int n = q.size();
//             vector<int> vtm;
//             int cline=-10000;
//             while(n--){
//                 pair<int, TreeNode*> temp = q.front();
//                 q.pop();

//                 int line = temp.first;
//                 if(cline==-10000) cline = line;
//                 TreeNode* node = temp.second;
//                 mp[line].push_back(node->val);
//                 vtm.push_back(node->val);
//                 if(node->left) q.push(make_pair(line-1, node->left));

//                 if(node->right) q.push(make_pair(line+1, node->right));
//                 sort(mp[line].begin(),mp[line].end());
//             }
//             // sort(vtm.begin(),vtm.end());
//             // mp[cline] = vtm;
//         }
        
//         for(auto m: mp){
//             vector<int> tmp = m.second;
//             // sort(tmp.begin(),tmp.end());
//             ans.push_back(tmp);
            
//         }
//         return ans;
        
//     }
    
    map<int,vector<pair<int,int> >>m;
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>>v;
        if(!root)
            return v;
        queue<pair<TreeNode*,pair<int,int>>> q;
        q.push({root,{0,0}});
        while(!q.empty())
        {
            int size=q.size();
            while(size)
            {
                TreeNode* temp=q.front().first;
                int col=q.front().second.first;
                int level=q.front().second.second;
                m[col].push_back({level,temp->val});
                if(temp->left)
                q.push({temp->left,{col-1,level+1}});
                if(temp->right)
                q.push({temp->right,{col+1,level+1}});
                q.pop();
                size--;
            }
        }
        for(auto it:m)
        {
            sort(it.second.begin(),it.second.end());
            vector<int> ans;
            for(auto i:it.second)
            ans.push_back(i.second);
            v.push_back(ans);
        }
        return v;
    }
};
