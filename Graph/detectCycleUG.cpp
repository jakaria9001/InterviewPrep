#include<bits/stdc++.h>
using namespace std;

bool dfs(vector<vector<int>>& adj, vector<bool>& visited,int src, int parent){
  visited[src]=true;
  for(auto i: adj[src]){
    if(!visited[i]){
      if(dfs(adj,visited,i,src)) return true;
    }else if(i!=parent)
          return true;
  }
  return false;
  
}
bool hasCycle(int V, vector<vector<int>>& adj){
  
  vector<bool>visited(V,false);
  
  for(int i=0;<V;i++){
    if(!visited){
      if(dfs(adj,visited,src,-1)) return true;
    }
  }
  return false;
}

int main(){
  vector<vector<int>> input, adj;
  for(int i=0;i<input.size();i++){
   adj[input[i][0]].push_back(input[i][1]);
   adj[input[i][1]].push_back(input[i][0]); 
  }
  cout<<hasCycle(adj)<<endl;
  return 0;
}

