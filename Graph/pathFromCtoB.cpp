int Solution::solve(vector<int> &A, const int B, const int C) {
    
    // There exist a directed edge from A[i] to i+1 for every 1 <= i < N. Also, it's guaranteed that A[i] <= i.
    int V = A.size();
    vector<vector<int>> adj(V+1);
    for(int i=0;i<V;i++){
        adj[A[i]].push_back(i+1);
    }
    
    // bfs: 
    if(B==C) return 1;
    
    bool visited[V+1] = {false};
    queue<int> q;
    q.push(C);
    visited[C] = true;
    while(!q.empty()){
        int temp = q.front();
        q.pop();
        for(auto i: adj[temp]){
            if(!visited[i]){
                if(i==B) return 1;
                q.push(i);
                visited[i]=true;
            }
        }
    }
    return 0;
}
