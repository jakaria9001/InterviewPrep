// Link : https://www.scaler.com/academy/mentee-dashboard/classroom/stacks-1/#assignment

void atBottom(stack<int> st, int x){
    if(st.empty()){
        st.push(x);
        return;
    }
    int tmp = st.top();
    st.pop();
    atBottom(st,x);
    st.push(tmp);
}
void reversed(stack<int> st){
    if(st.size()==0) return;
    int tmp = st.top();
    st.pop();
    reversed(st);
    atBottom(st,tmp);
}

vector<int> Solution::solve(vector<int> &A) {
    
    // for(int x : A)
    //     st.push(x);
    // std::vector<A> m_vec = /* ... */;
    // std::stack<A, std::vector<A>> m_stack(m_vec);
    
    // stack<int, vector<int> > st(A);
    
    // reversed(st);
    // // while(st.size()){
    // //     ans.push_back(st.top());
    // //     st.pop();
    // // }
    // vector<int> ans(st.begin(),st.end());
    // return ans;
    reverse(A.begin(),A.end());
    return A;
}
