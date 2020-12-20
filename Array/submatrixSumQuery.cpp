vector<int> Solution::solve(vector<vector<int> > &A, vector<int> &B, vector<int> &C, vector<int> &D, vector<int> &E) {
    // int n = A.size(), m = A[0].size();
    // vector<vector<int> > presum(n,vector<int>(m));
    
    // // storing presum :
    //   // first row:
    // for(int i=0;i<m;i++)
    //     presum[0][i] = A[0][i]; 
    // // column wise sum
    // for(int i=1;i<n;i++)
    //     for(int j=0;j<m;j++)
    //         presum[i][j] = presum[i-1][j]+A[i][j];
    // // row wise sum 
    // for(int i=0;i<n;i++)
    //     for(int j=1;j<m;j++)
    //         presum[i][j] += presum[i][j-1];
            
            
    // // ans array:
    // vector<int> ans;
    // // query 1:
    // int sti = B[0]-1, stj = C[0]-1;
    // int endi = D[0]-1, endj = E[0]-1;
    
    // int result = presum[endi][endj];
    // if(sti>0)
    //     result -= presum[sti-1][endj];
    // if(stj>0)
    //     result -= presum[stj][endi-1];
    // if(sti>0 && stj>0) result += presum[sti-1][stj-1];
    
    // ans.push_back(result);
    
    // // query 2:
    // sti =B[1]-1, stj = C[1]-1;
    // endi = D[1]-1, endj = E[1]-1;
    
    // result = presum[endi][endj];
    // if(sti>0)
    //     result -= presum[sti-1][endj];
    // if(stj>0)
    //     result -= presum[stj][endi-1];
    // if(sti>0 && stj>0) result += presum[sti-1][stj-1];
    
    // ans.push_back(result);
    
    // return ans;
    
    // Alt : 
    int n = A.size(), m = A[0].size();
    
    long long int mod = 1000000007;
    
    long long int dp[n+1][m+1];
    
    for(int i=0; i<=n; i++)
    {
        
        dp[i][0] = 0;
        
    }
    
    for(int i=0; i<=m; i++)
    {
        
        dp[0][i] = 0;
        
    }
    
    for(int i=1; i<=n; i++)
    {
        
        for(int j=1; j<=m; j++)
        {
            
            dp[i][j] = (mod + dp[i-1][j]%mod + dp[i][j-1]%mod + A[i-1][j-1]%mod - dp[i-1][j-1]%mod)%mod;
            
        }
        
    }
    
    vector<int> ans;
    
    for(int i=0; i<B.size(); i++)
    {
        
        int row1 = B[i];
        
        int col1 = C[i];
        
        int row2 = D[i];
        
        int col2 = E[i];
        
        int sum = (mod + dp[row2][col2]%mod - dp[row1 - 1][col2]%mod - dp[row2][col1 - 1]%mod + dp[row1 - 1][col1 - 1]%mod)%mod;
        
        if(sum < 0)
        {
            
            sum = sum + mod;
            
        }
        
        ans.push_back(sum%mod);
        
    }
    
    return ans;
}
