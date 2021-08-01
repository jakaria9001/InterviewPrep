const int INF = 10000;

typedef pair<int, int> iPair;

vector<int> shortestPath(vector<vector<pair<int,int>> >& adj, int V, int src)
{
    priority_queue< iPair, vector <iPair> , greater<iPair> > pq;
    
    vector<int> dist(V, INF);
  
    pq.push(make_pair(0, src));
    dist[src] = 0;
  
    while (!pq.empty())
    {
       
        int u = pq.top().second;
        pq.pop();
  
        for (auto x : adj[u])
        {
            int v = x.first;
            int weight = x.second;
  
            if (dist[v] > dist[u] + weight)
            {
                // Updating distance of v
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v], v));
            }
        }
    }
  
    return dist;
}

vector<int> Solution::solve(int A, vector<vector<int> > &B, int C) {
    
    
    vector<vector<pair<int,int>> > adj(A);
    for(auto it: B){
        adj[it[0]].push_back(make_pair(it[1],it[2]));
        adj[it[1]].push_back(make_pair(it[0],it[2]));
    }
    
    vector<int> ans = shortestPath(adj,A,C);
    for(int &x: ans) if(x==INF) x = -1;
    return ans;
}
