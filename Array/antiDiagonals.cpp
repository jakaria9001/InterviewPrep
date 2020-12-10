// Anti-diagonals

vector<vector<int> > Solution::diagonal(vector<vector<int> > &A) {
    
    int n = A.size();
    int size = 2*n-1;
    vector<vector<int> > ans(size);
    
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            ans[i+j].push_back(A[i][j]);
            
    return ans;
}
