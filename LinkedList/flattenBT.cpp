
TreeNode* Solution::flatten(TreeNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    if(!A) return A;
    stack<TreeNode*> st;
    st.push(A);
    
    while(!st.empty()){
        TreeNode* temp = st.top();
        st.pop();
        
        if(temp->right) st.push(temp->right);
        if(temp->left) st.push(temp->left);
        
        if(!st.empty()) temp->right = st.top();
        
        temp->left = NULL;
    }
    return A;
}
