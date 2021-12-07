// https://www.geeksforgeeks.org/maximum-profit-sale-wines/
int dp[2000][2000];
// recursive
int solve1(vector<int> &price, int i, int j, int year)
{
    if(i>j) return 0;
    if(i==j) return price[i]*year;
    
    int left = price[i]*year + solve1(price,i+1,j,year+1);
    int right = price[j]*year +solve1(price,i,j-1,year+1);
    return max(left,right);
}
// memoized
int helper(vector<int> &price, int i, int j, int year){
    if(i>j) return 0;
    if(i==j) return year*price[i];

    if(dp[i][j]!=-1) return dp[i][j];

    int left = year*price[i] + helper(price, i+1, j, year+1);
    int right = year*price[j] + helper(price, i, j-1,year+1);

    return dp[i][j] = max(left,right);
}
int Solution::solve(vector<int> &A) {
    
    memset(dp,-1,sizeof(dp));
    return helper(A,0,A.size()-1, 1);
}
