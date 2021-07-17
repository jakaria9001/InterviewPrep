/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 vector<int> ans;
 
 void printLeaves(TreeNode* root)
{
    if (root == NULL)
        return;
 
    printLeaves(root->left);
 
    // Print it if it is a leaf node
    if (!(root->left) && !(root->right))
        ans.push_back(root->val);
 
    printLeaves(root->right);
}
 
// A function to print all left boundary nodes, except a leaf node.
// Print the nodes in TOP DOWN manner
void printBoundaryLeft(TreeNode* root)
{
    if (root == NULL)
        return;
 
    if (root->left) {
 
        // to ensure top down order, print the node
        // before calling itself for left subtree
        ans.push_back(root->val);
        printBoundaryLeft(root->left);
    }
    else if (root->right) {
        ans.push_back(root->val);
        printBoundaryLeft(root->right);
    }
    // do nothing if it is a leaf node, this way we avoid
    // duplicates in output
}
 
// A function to print all right boundary nodes, except a leaf node
// Print the nodes in BOTTOM UP manner
void printBoundaryRight(TreeNode* root)
{
    if (root == NULL)
        return;
 
    if (root->right) {
        // to ensure bottom up order, first call for right
        // subtree, then print this node
        printBoundaryRight(root->right);
        ans.push_back(root->val);
    }
    else if (root->left) {
        printBoundaryRight(root->left);
        ans.push_back(root->val);
    }
    // do nothing if it is a leaf node, this way we avoid
    // duplicates in output
}
 
// A function to do boundary traversal of a given binary tree
void printBoundary(TreeNode* root)
{
    if (root == NULL)
        return;
 
    ans.push_back(root->val);
 
    // Print the left boundary in top-down manner.
    printBoundaryLeft(root->left);
 
    // Print all leaf nodes
    printLeaves(root->left);
    printLeaves(root->right);
 
    // Print the right boundary in bottom-up manner
    printBoundaryRight(root->right);
}
 
vector<int> Solution::solve(TreeNode* A) {

    ans.clear();
    printBoundary(A);
    return ans;
    
}
