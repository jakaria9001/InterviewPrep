vector<int> Solution::solve(int A, vector<vector<int> > &B) {
    vector<int> in(A+1,0);
    vector<vector<int>> adj(A+1);
    for(auto it: B){
        adj[it[0]].push_back(it[1]);
        in[it[1]]++;
    }
    priority_queue<int,vector<int>,greater<int>> pq;
    for(int i=1;i<=A;i++){
        if(in[i]==0)
            pq.push(i);
    }
    vector<int> ans;
    while(!pq.empty()){
        int temp = pq.top();
        pq.pop();
        ans.push_back(temp);
        for(int x: adj[temp]){
            in[x]--;
            if(in[x]==0) pq.push(x);
        }
    }
    if(ans.size()!=A) ans.clear();
    return ans;
            
}
/* My implementation:
bool hasCycle(int src, vector<bool> &vis, vector<bool>& dfsVis, vector<vector<int>>& adj){
    vis[src] = true;
    dfsVis[src] = true;
    for(int i: adj[src]){
        if(!vis[i]){
            if(hasCycle(i,vis, dfsVis,adj));
        }else if(dfsVis[i]) return true;
    }
    dfsVis[src] = false;
    return false;
}
void topoSort(int v, stack<int> &st, vector<bool> &visited, vector<vector<int>>& adj){
    visited[v] = true;
    for(int i: adj[v]){
        if(!visited[i]){
            topoSort(i,st,visited,adj);
        }
    }
    st.push(v);
}
vector<int> Solution::solve(int A, vector<vector<int> > &B) {
    vector<bool> vis(10009, false), dfsVis(10009, false);
    vector<int> ans;
    vector<vector<int>> adj(10009);
    for(int i=0;i<B.size();i++){
        adj[B[i][0]].push_back(B[i][1]);
    }
    for(int i=1;i<=A;i++)
        if(!vis[i])
            if(hasCycle(i, vis, dfsVis,adj)) return {};
    fill(vis.begin(), vis.end(), false);
    
    for(int i=1;i<=A;i++){
        if(!vis[i]){
            stack<int> st;
            vector<int> temp;
            topoSort(i,st,vis,adj);
            while(!st.empty()){
                int t = st.top();
                st.pop();
                temp.push_back(t);
            }
            // sort(temp.begin(),temp.end());
            ans.insert(ans.end(),temp.begin(),temp.end());
        }
    }
    return ans;
}


*/
