vector<int> Solution::solve(vector<vector<int> > &A, vector<int> &B, vector<int> &C, vector<int> &D, vector<int> &E) {
    int n = A.size(), m = A[0].size();
    vector<vector<int> > presum(n,vector<int>(m));
    
    // storing presum :
      // first row:
    for(int i=0;i<m;i++)
        presum[0][i] = A[0][i]; 
    // column wise sum
    for(int i=1;i<n;i++)
        for(int j=0;j<m;j++)
            presum[i][j] = presum[i-1][j]+A[i][j];
    // row wise sum 
    for(int i=0;i<n;i++)
        for(int j=1;j<m;j++)
            presum[i][j] += presum[i][j-1];
            
            
    // ans array:
    vector<int> ans;
    // query 1:
    int sti = B[0]-1, stj = D[0]-1;
    int endi = B[1]-1, endj = D[1]-1;
    
    int result = presum[endi][endj];
    if(sti>0)
        result -= presum[sti-1][stj];
    if(stj>0)
        result -= presum[sti][stj-1];
    if(sti>0 && stj>0) result += presum[sti-1][stj-1];
    
    ans.push_back(result);
    
    // query 2:
    sti = C[0]-1, stj = E[0]-1;
    endi = C[1]-1, endj = E[1]-1;
    
    result = presum[endi][endj];
    if(sti>0)
        result -= presum[sti-1][stj];
    if(stj>0)
        result -= presum[sti][stj-1];
    if(sti>0 && stj>0) result += presum[sti-1][stj-1];
    
    ans.push_back(result);
    
    return ans;
}
