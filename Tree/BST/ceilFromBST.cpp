// Link: https://www.codingninjas.com/codestudio/problems/ceil-from-bst_920464
int findCeil(BinaryTreeNode<int> *node, int x){

  // Write your code here
     if(!node) return -1;
     if(node->data == x) return x;
     
     if(node->data < x)
         return findCeil(node->right, x); 
     int l = findCeil(node->left,x);
     return (l>=x)?l:node->data;

}
