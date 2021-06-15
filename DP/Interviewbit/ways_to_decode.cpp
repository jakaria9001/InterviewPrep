// Link : https://leetcode.com/problems/decode-ways/

const int maxn = 100009;
const int mod = 1000000007;
int dp[maxn];



int r_ways(int ind, string& arr){
    
    if(ind >= arr.length()) return 1;
    
    if(dp[ind]!=-1) return dp[ind];
    
    if(arr[ind]=='0') return dp[ind]=0;
    
    
    
    int ans = r_ways(ind+1, arr);
    ans %= mod;
    
    if(ind+1 < arr.length()){
        int td = ((arr[ind]-'0')*10) + ((arr[ind+1]-'0'));
        
        if(td>=10 && td<=26) ans += r_ways(ind+2, arr);
        ans%=mod;
    }
    return dp[ind] = ans;
    ans%=mod;
    
}
int solve(int index, string & A) {
  if (index >= A.size())
    return 1;
  if (dp[index] != -1)
    return dp[index];
  if (A[index] == '0')
    return dp[index] = 0;
  int ans = solve(index + 1, A);
  ans %= mod;
  if (index + 1 < A.size()) {
    int num = ((A[index] - '0') * 10) + (A[index + 1] - '0');
    if (num >= 10 && num <= 26)
      ans += solve(index + 2, A);
    ans %= mod;
  }
  return dp[index] = ans;
  ans %= mod;
}

int Solution::numDecodings(string A) {
    
    memset(dp, -1, sizeof(dp));
    return r_ways(0,A);
    
    // int recursiveWays = r_ways(0, A);

    // return recursiveWays;
    
}
