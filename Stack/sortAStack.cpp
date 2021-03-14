void insertAtBottom(stack<int>& st, int x){
  if(st.size()==0){ st.push(x); return; }
  int tmp = st.top();
  st.pop();
  insertAtBottom(st,x);
  st.push(tmp);
}
void sortStack(stack<int>& st){
  if(st.empty()) return;
  int temp = st.top();
  st.pop();
  sortStack(st);
  insertAtBottom(st, temp);
  
}

int main(){
    stack<int> st;
  st.push(3);
  st.push(2);
  st.push(6);
  st.push(9);
  st.push(1);
  sortStack(st);
  while(st.size()){
      cout<<st.top()<<" ";
      st.pop();
  }
  return 0;
}
