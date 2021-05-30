// Link : interviewbit.com/problems/generate-all-parentheses-ii/


vector<string> ans;
void createValidPars(int ind, char temp[], int open, int close, int n){
    if(ind == 2*n){
        temp[2*n] = '\0';
        string temp1 = (temp);
        ans.push_back(temp1);
        // temp.clear();
        return;
    }
    
    if(open>close){
        // temp.push_back(')');
        temp[ind] = ')';
        createValidPars(ind+1, temp, open, close+1, n);
    }
    if(open<n){
        // temp.push_back('(');
        temp[ind] = '(';
        createValidPars(ind+1, temp, open+1, close, n);
    }
    
}

vector<string> Solution::generateParenthesis(int A) {
    ans.clear();
    
    char temp[2*A];
    createValidPars(0, temp, 0, 0, A);
    reverse(ans.begin(),ans.end());
    // ans.pop_back();
    // cout<<ans[ans.size()-1]<<endl;
    return ans;
}
