/** Link: https://leetcode.com/problems/populating-next-right-pointers-in-each-node/
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
void Solution::connect(TreeLinkNode* A) {
    if(!A) return;
    
    queue<TreeLinkNode*> q;
    q.push(A);
    
    while(!q.empty()){
        TreeLinkNode *temp = q.front();
        q.pop();
        if(temp->left && temp->right){
            temp->left->next = temp->right;
            if(temp->next)
                temp->right->next = temp->next->left;
             q.push(temp->left);
             q.push(temp->right);
        }
        
        
    }
    
}
