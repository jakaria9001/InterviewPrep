// Link: https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/

string Solution::solve(string A) {
    stack<char> st;


    for(char ch: A){
        bool flag = 1;
        while(!st.empty() && ch==st.top()){
            st.pop();
            flag = 0;
        }
        if(flag) st.push(ch);
    }

    string ans="";

    while(!st.empty()){
        ans+= st.top();
        st.pop();
    }
    reverse(ans.begin(),ans.end());
    return ans;


}
