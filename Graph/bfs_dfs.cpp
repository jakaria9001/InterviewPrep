vector<vector<int>> adj(V);

void bfs(){
  bool visited[V]; //V or V+1 depending on the start form 0 or 1;
  queue<int> q;
  q.push(0);
  visited[0]=true;
  while(!q.empty()){
    int temp=q.front();
    q.pop();
    cout<<temp<<" ";
    for(auto i: adj[temp]){
      if(!visited[i]){
        visited[i]=true;
        q.push(i);
      }
    }
  }
}

void dfs(int src){
  visited[src]=true;
  cout<<src<<" ";
  for(auto i:adj[src]){
    if(!visited[i]){
      dfs(i);
    }
  } 
}
