
int dp[100005];

int rodCutting(vector<int> price, int n){
  if(n<=0)  return 0;
  if(dp[n]!=-1) return dp[n];
  
  int maxPrice = INT_MIN;
  for(int i=0;i<n;i++)
      maxPrice = max(maxPrice, price[i]+rodCutting(price, n-i-1));
  
  return dp[n]=maxPrice;
}

