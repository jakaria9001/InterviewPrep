// Link : https://www.interviewbit.com/problems/max-sum-without-adjacent-elements/

int maxSum(vector<int>& dp, vector<int>& arr,int n, int i){
    if(i==0) return arr[0];
    if(i==1) return max(arr[0], arr[1]);
    
    if(dp[i]!=-1) return dp[i];
    
    int ans = max(maxSum(dp, arr, n, i-1),(arr[i] + maxSum(dp, arr,n,i-2)));

    return dp[i] = ans;
}

int Solution::adjacent(vector<vector<int> > &A) {
    
    // this can be reduced to robbery problem by taking the max element from each column
    
    // ways(i) = max(ways(i-1) + arr[i]+ways(i-2)) // over the whole array.
    int n = A[0].size();
    vector<int> arr(n,-1);
    vector<int> dp(n,-1);
    
    for(int i=0;i<n;i++){
        arr[i] = max(A[0][i], A[1][i]);
    }
    // memset(dp,-1,sizeof(dp));
    
    return maxSum(dp, arr,n, n-1);
    
    
}
