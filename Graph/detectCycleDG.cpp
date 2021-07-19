bool cycleCheck(int v, vector<int> &visited, vector<int> &dfsVisited,  vector<vector<int>> &adj){
    visited[v]=true;
    dfsVisited[v] = true;
    for(auto i: adj[v]){
        if(!visited[i]){
            if(cycleCheck(i,visited, dfsVisited, adj)) return true;
    
        }
        else if(dfsVisited[i]) return true;
    }
    dfsVisited[v] = false;
    return false;
}

int Solution::solve(int A, vector<vector<int> > &B) {
    vector<vector<int>> adj(A+1);
    
    vector<int> visited(A+1, false), dfsVisited(A+1, false);
    
    for(int i=0;i<B.size();i++)
        adj[B[i][0]].push_back(B[i][1]);
    
    for(int i=1;i<=A;i++){
        if(!visited[i])
            if(cycleCheck(i, visited, dfsVisited, adj)) return true;
    }
    return false;
}
