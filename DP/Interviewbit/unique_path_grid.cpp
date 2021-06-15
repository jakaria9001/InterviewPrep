// Link : https://www.interviewbit.com/problems/grid-unique-paths/
int dp[3000][3000];

int ways(int i, int j){
    
    if(i==0 || j==0) return 1;
    if(dp[i][j]!=-1) return dp[i][j];
    int ans =  (ways(i-1,j)+ways(i, j-1));
    return dp[i][j] = ans;
}

int Solution::uniquePaths(int A, int B) {
    memset(dp,-1,sizeof(dp));
    return ways(A-1, B-1);
}
/* // With Obstacles : 

int dp[200][200];

int ways(vector<vector<int> > &A, int i, int j){
    int n = A.size();
    int m = A[0].size();
    
    if(i>=n || j>=m) return 0;
    
    if(i==n-1 && j==m-1) return (A[i][j]!=1);
    if(A[i][j]==1) return 0;
    
    if(dp[i][j]!=-1) return dp[i][j];
    int ans = ways(A, i+1, j) + ways(A, i, j+1);
    
    return dp[i][j]=ans;
    
    
}

int Solution::uniquePathsWithObstacles(vector<vector<int> > &A) {
    
    memset(dp, -1, sizeof(dp));
    return ways(A, 0, 0);
}


*/
