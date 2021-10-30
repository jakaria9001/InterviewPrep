// Link : https://leetcode.com/problems/implement-stack-using-queues/
queue <int> q1,q2 ;
UserStack() {
    
}

void push(int x) {
   /*Method-1:Using 2 queues O(N)Aux Space
   while(!q1.empty()){
       q2.push(q1.front());
       q1.pop();
   } 
    q1.push(x);
    while(!q2.empty()){
        q1.push(q2.front());
        q2.pop();
    }*/
    
    //M-2:Method-2:Better method using 1 queue O(1) Aux Space
    q1.push(x);
    for(int i=0;i<q1.size()-1;i++){
        q1.push(q1.front());
        q1.pop();
    }
}

int pop() {
    int t=q1.front();
    q1.pop();
    return t;
}

int top() {
  return q1.front();  
}

bool empty() {
   return (q1.empty()); 
}
