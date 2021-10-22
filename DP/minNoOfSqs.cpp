// Link: https://www.geeksforgeeks.org/minimum-number-of-squares-whose-sum-equals-to-given-number-n/

int fun(int n){
    
    if(n<=3) return n;
    
    int dp[n+1];
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;
    
    for(int i=4;i<=n;i++){
        dp[i] = i;
        for(int x=1;x<=ceil(sqrt(i));x++){
            int t = x*x;
            if(t>i) break;
            else
                dp[i] = min(dp[i], 1+dp[i-t]);
        }
        
    }
    return dp[n];
}


int Solution::countMinSquares(int A) {
    return fun(A);
}
