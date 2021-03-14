// Reverse a given stack : 

// 1. It can be reversed using another stack.
// 2. using recursion : 
void insertAtBottom(int x) { }
void reverse(){
    if(st.empty()) return;
    int tmp = st.top();
    st.pop();
    reverse();
    insertAtBottom(tmp);
}

int main(){
    st.push(1);
    st.push(3);
    reverse();
}
