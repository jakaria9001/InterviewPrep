// kth-largest elements in a stream

vector<int> Solution::solve(int A, vector<int> &B) {
    priority_queue<int, vector<int>, greater<int>> pq;
    vector<int> ans;
    
    for(int i=0;i<(A-1);i++){
        ans.push_back(-1);
        pq.push(B[i]);
    }
    pq.push(B[A-1]);
    ans.push_back(pq.top());
    for(int i=A;i<B.size();i++){
        if(B[i]>pq.top()){
            pq.pop();
            pq.push(B[i]);
        }
        ans.push_back(pq.top());
    }
    return ans;
    // for(int i=0;i<B.size();i++){
    //     if(i<A-1) pq.push(B[i]);
    //     else if(B[i]>=pq.top()){
    //         pq.pop();
    //         pq.push(B[i]);
    //     }
        
    //     if(i<A-1) ans.push_back(-1);    
    //     else {
    //         ans.push_back(pq.top());
    //     }
    // }
    // return ans;
    
}
