// Link: https://www.codingninjas.com/codestudio/problems/unival-trees_697311
/*************************************************************
 
    Following is the Binary Tree node structure

    class BinaryTreeNode 
    {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/
 pair<int, bool> postorder(BinaryTreeNode<int> *root){
    if(!root) return {0,true};
    
    auto left = postorder(root->left);
    auto right = postorder(root->right);
     
    int leftVal = left.first, rightVal = right.first;
    int isLeft = left.second, isRight = right.second;
    int total = leftVal+rightVal;
    
    if(isLeft && isRight){
        if(root->left && root->data!=root->left->data)
            return {total,false};
        if(root->right && root->data!=root->right->data)
            return {total,false};
        return {total+1, true};
    }
     
    return {total, false};
}
int countUnivalTrees(BinaryTreeNode<int> *root)
{
    // Write your code here.
    if(!root) return 0;
    
    return postorder(root).first;
   	
}
