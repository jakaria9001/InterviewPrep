// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};


 // } Driver Code Ends
//Structure of binary tree
/*struct Node
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/
// Link : https://practice.geeksforgeeks.org/problems/top-view-of-binary-tree/1
class Solution{
  public:
    // function should print the topView of the binary tree
    vector<int> topView(struct Node *root)
    {
        //Your code here
        map<int, int> mp;   // vertical-line, top-element
        vector<int> result;
        if(!root) return result;
        
        queue<pair<int, Node*>> q;
        q.push(make_pair(0,root));
        
        while(!q.empty()){
            pair<int, Node*> tmp = q.front();
            q.pop();
            
            Node *temp = tmp.second;
            int line = tmp.first;
            if(mp.find(line)==mp.end())
                mp[line] = temp->data;
            if(temp->left) q.push(make_pair(line-1,temp->left));
            if(temp->right) q.push(make_pair(line+1,temp->right));
        }
        
        for(auto m: mp)
            result.push_back(m.second);
        return result;
    }
};



// { Driver Code Starts.


int main()
{
    int t;cin>>t;
    while(t--)
    {
        int n,i,k;
        cin>>n;
        i=n;

        Node* root=NULL;
        queue <Node*> q;
        while(i>0)
        {
            int a,b;
            char c;
            cin>> a >> b >> c;
            if(!root){
                root = new Node(a);
                q.push(root);
            }
            Node* pick = q.front();
            q.pop();

            if(c == 'L'){
                pick->left = new Node(b);
                q.push( pick->left );
            }
            cin>> a >> b >> c;
            if(c == 'R'){
                pick->right = new Node(b);
                q.push( pick->right );
            }
            i-=2;
        }
//        inorder(root);
//        cout<<endl;
        Solution obj;
        vector<int> res = obj.topView(root);
        
        for(int i=0; i<res.size(); i++)
            cout<<res[i]<<" ";
        cout<<endl;
    }
    return 0;
}




  // } Driver Code Ends
