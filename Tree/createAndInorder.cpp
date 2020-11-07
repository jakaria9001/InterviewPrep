#include <iostream>
#include <stack> 

using namespace std;

struct Node {
    
    int data;
    struct Node *left, *right;
    Node(int data){
        this->data = data;
        left = right = NULL;
    }
};

void inorder(struct Node* root){
    
    if(root == NULL)
        return;
    inorder(root->left);
    cout<< root->data <<" ";
    inorder(root->right);
    
}

void inorderWithRec(struct Node* root){
    stack<Node*> s;
    Node* curr = root;
    while(curr!=NULL || !s.empty()){
        while(curr != NULL){
            s.push(curr);
            curr = curr->left;
        }
        
        curr = s.top();
        s.pop();
        
        cout<< curr->data << " ";
        curr=curr->right;
    }
}
// Making a tree from an array :

Node* newNode(int data){
    Node* newnode = (Node*)malloc(sizeof(Node));
    newnode->data = data;
    newnode->left = newnode->right = NULL;
    return newnode;
}
Node* makeLevelOrderTree(int arr[],Node*root, int i, int n){
    if(i<n){
        Node*temp = newNode(arr[i]);
        root = temp;
        root->left = makeLevelOrderTree(arr, root->left,2*i+1,n);
        root->right = makeLevelOrderTree(arr,root->right, 2*i+2,n);
    }
    return root;
}

int main()
{
    
    int arr[] = {1,2,3,4,5};
    struct Node *root = new Node(1); 
    
    root->left             = new Node(2); 
    root->right         = new Node(3); 
    root->left->left     = new Node(4); 
    root->left->right = new Node(5); 
    
    // making a tree from a given array : 
    Node *root1=NULL ,*root2 ;
    int arr1[100];
    int n;cin>>n;
    for(int i=0;i<n;i++) cin>>arr1[i];
    root2 = makeLevelOrderTree(arr1,root1, 0 , n);
    
    inorder(root2);
    cout<<endl;
    inorder(root);
    cout<<endl;
    inorderWithRec(root);
    return 0;
}
