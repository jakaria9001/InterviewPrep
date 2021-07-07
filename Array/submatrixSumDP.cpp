

#define ll long long int 
const ll mod = (ll) 1e9+7;

int add(int x, int y) {
    return ( ((x+y)%mod) + mod)%mod;
}
vector<int> Solution::solve(vector<vector<int> > &A, vector<int> &B, vector<int> &C, vector<int> &D, vector<int> &E) {
    // (B[i], C[i]) represents the top left corner of the i'th query.
    // (D[i], E[i]) represents the bottom right corner of the i'th query.

    vector<int> ans;
    int n = A.size(), m = A[0].size();
    
    // calculating presum:
    
    int presum[n][m] = {0};
    presum[0][0] = A[0][0]%mod;
    for(int i=1;i<n;i++)
        presum[i][0] = add(A[i][0], presum[i-1][0]);
    for(int i=1;i<m;i++)
        presum[0][i] = add(A[0][i]%mod , presum[0][i-1]);
        
    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            presum[i][j] = add(add(A[i][j] , presum[i-1][j]) ,  add(presum[i][j-1], -1*presum[i-1][j-1]) );
        }
    }
    
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         cout<<presum[i][j]<<" ";
    //         // presum[i][j] = A[i][j] + presum[i-1][j] + presum[i][j-1] - presum[i-1][j-1];
    //     }
    //     cout<<endl;
    // }
    for(int i=0;i<B.size();i++){
        int r1 = B[i]-1, c1 = C[i]-1, r2= D[i]-1, c2 = E[i]-1;
    
        ll result = add(add(presum[r2][c2],((r1>0&&c1>0)?presum[r1-1][c1-1]:0)), -1*add(((c1>0)?presum[r2][c1-1]:0), ((r1>0)?presum[r1-1][c2]:0))) ;
        
        ans.push_back(result%mod);
    }
    
    return ans;
      
    
}
