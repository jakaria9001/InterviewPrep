// Link: https://practice.geeksforgeeks.org/problems/connect-nodes-at-same-level/1/

class Solution
{
    public:
    //Function to connect nodes at same level.
    void connect(Node *root)
    {
       // Your Code Here
       if(!root) return;
       queue<Node*> q;
       q.push(root);
       while(!q.empty()){
           int n = q.size();
           Node* prev = q.front();
           q.pop();
           if(prev->left) q.push(prev->left);
           if(prev->right) q.push(prev->right);
           
           for(int i=1;i<n;i++){
               Node *temp = q.front();
               q.pop();
               prev->nextRight = temp;
               prev = temp;
               
               if(temp->left) q.push(temp->left);
               if(temp->right) q.push(temp->right);
           }
           prev->nextRight = NULL;
       }
    }    
      
};
