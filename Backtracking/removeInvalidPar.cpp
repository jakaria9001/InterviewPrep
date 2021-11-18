// Link: https://leetcode.com/problems/remove-invalid-parentheses/

void removeInvalidParentheses(unordered_set<string> & res, string s, int ind, string prefix, int num_remove_l, int num_remove_r, int pair, int left_rem, int right_rem) {
        if (ind==s.length()){
            if (num_remove_l==0 && num_remove_r==0 && pair==0)res.insert(prefix);
            return;
        }
        
        
        // for(int i=ind;i<s.length();i++){
            if (s[ind]=='('){
                if (num_remove_l>0){
                   removeInvalidParentheses(res, s, ind+1, prefix,num_remove_l-1, num_remove_r, pair, left_rem-1, right_rem);
                }
                if (left_rem>num_remove_l){
                    prefix.push_back('(');
                    removeInvalidParentheses(res, s, ind+1, prefix,num_remove_l, num_remove_r, pair+1, left_rem-1, right_rem);
                prefix.pop_back();
                }
                
            }else if (s[ind]==')'){
                if (num_remove_r>0){
                   removeInvalidParentheses(res, s, ind+1, prefix,num_remove_l, num_remove_r-1, pair, left_rem, right_rem-1);
                }
                if (pair>0 && right_rem>num_remove_r){
                prefix.push_back(')');
                removeInvalidParentheses(res, s, ind+1, prefix,num_remove_l, num_remove_r, pair-1, left_rem, right_rem-1);
                prefix.pop_back();
                }
            
            }else{
                prefix.push_back(s[ind]);
                removeInvalidParentheses(res, s, ind+1, prefix,num_remove_l, num_remove_r, pair,  left_rem, right_rem);
                prefix.pop_back();
            }
    }
    
    

vector<string> Solution::solve(string s) {
    int right=0;
        int left=0;
        int right_rem=0;
        int left_rem=0;
        for(auto ch:s){
            if (ch=='('){
                left++;
                left_rem++;
            } 
            else if (ch==')'&&left>0) {
                left--;
                right_rem++;
            }
            else if (ch==')'&&left==0){
                right++;
                right_rem++;
            } 
        }
        unordered_set<string> res;
        // cout<<"func called "<<left<<" "<<right<<endl;
        removeInvalidParentheses(res, s, 0, "",left, right, 0,  left_rem, right_rem);
        vector<string> result(res.begin(),res.end());
        return result;
}
