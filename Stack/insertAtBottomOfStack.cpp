// Insert value a the bottom of a stack

stack<int> st;

insertAtBottom(int x){
  if(st.empty()){
     st.push(x);
     return;
  }
  int tmp = st.top();
  st.pop();
  insertAtBottom(x);
  st.push(tmp);
}

int main(){
  
  st.push(1);
  st.push(5);
  insertAtBottom(10);
  
}
