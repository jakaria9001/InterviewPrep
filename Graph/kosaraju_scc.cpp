//Link: https://www.geeksforgeeks.org/strongly-connected-components/
vector<vector<int>> ans;
vector<int> temp;

void dfs(int node, stack<int> &st, vector<int> &vis, vector<int> adj[]) {
    vis[node] = 1; 
    for(auto it: adj[node]) {
        if(!vis[it]) {
            dfs(it, st, vis, adj); 
        }
    }
    
    st.push(node); 
}
void revDfs(int node, vector<int> &vis, vector<int> transpose[]) {
    // cout << node << " "; 
    temp.push_back(node);
    vis[node] = 1; 
    for(auto it: transpose[node]) {
        if(!vis[it]) {
            revDfs(it, vis, transpose); 
        }
    }
}

vector<vector<int> > Solution::solve(int A, vector<vector<int> > &B) {
    ans.clear();
    temp.clear();


    int n = A;
    int m = B.size();

    vector<int> adj[n]; 
	for(int i = 0;i<m;i++) {
	    int u = B[i][0]-1, v = B[i][1]-1;
	    // cin >> u >> v; 
	    adj[u].push_back(v);
	}
	
	stack<int> st;
	vector<int> vis(n, 0); 
	for(int i = 0;i<n;i++) {
	    if(!vis[i]) {
	        dfs(i, st, vis, adj); 
	    }
	} 
	
	vector<int> transpose[n]; 
	
	for(int i = 0;i<n;i++) {
	    vis[i] = 0; 
	    for(auto it: adj[i]) {
	        transpose[it].push_back(i); 
	    }
	}
	
	
	
	while(!st.empty()) {
	    int node = st.top();
	    st.pop(); 
        temp.clear();
	    if(!vis[node]) {
	        // cout << "SCC: "; 
	        revDfs(node, vis, transpose); 
	        // cout << endl;
            sort(temp.begin(),temp.end());
            ans.push_back(temp);

	    }
	}
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            ans[i][j]=ans[i][j]+1;
        }
        // cout<<" br ";
    }
    return ans;
}
