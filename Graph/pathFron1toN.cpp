// Link: https://www.interviewbit.com/problems/path-in-directed-graph/
bool dfs(vector<vector<int>>&adj, vector<bool>&vis, int start, int end){
    vis[start] = true;
    if(start==end) return true;

    for(auto i: adj[start]){

            if(!vis[i]){
                if(dfs(adj, vis,i,end)) return true;
            }
    }
    return false;
}
int Solution::solve(int A, vector<vector<int> > &B) {
    vector<vector<int>> adj(A+1);
    for(int i=0;i<B.size();i++){
        adj(B[i][0]).push_back(B[i][1]);
    }
    vector<int> visited(A+1, false);
    return dfs(adj, visited, 1, A);
}
