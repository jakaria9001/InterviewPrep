int getMaxWidth(Node* root)
    {
        
       // Your code here
       if(!root) return 0;
       
       int ans = -1;
       queue<Node*> q;
       q.push(root);
       while(!q.empty()){
           int n = q.size();
           
            if(n>=ans) ans = n;
           while(n--){
               Node* temp = q.front();
               q.pop();
               if(temp->left) q.push(temp->left);
               if(temp->right) q.push(temp->right);
           }
       }
       return ans;
    }
