// https://www.interviewbit.com/problems/longest-common-subsequence/
const int SZ = 2000;
int dp[SZ][SZ];
string s1, s2;

int lcs(int l1, int l2){
    if(l1==0 || l2==0) 
        return 0;
     
    if(dp[l1][l2]!=-1) return dp[l1][l2];
    
    if(s1[l1-1]==s2[l2-1]) return dp[l1][l2]=(1+lcs(l1-1, l2-1));
    
    return dp[l1][l2]=max(lcs(l1-1,l2), lcs(l1, l2-1));
    
    // return ans;
}
int Solution::solve(string A, string B) {

    s1 = A;
    s2 = B;
    
    
    int l1 = A.length();
    int l2 = B.length();
    // cout<<s1<<" "<<s2<<" ";
    
    // recursive : top down : 
    // memset(dp,-1, sizeof(dp));
    
    // return lcs(l1, l2);
    
    int LTable[l1+1][l2+1]; // LTable[i][j] will store the length of LCS of s1 till length i, and s2 till length j
    
    // s1 ="", s2="dfjg" // we are sure that LCS is 0;
    // lly, s1="sone", s2="" // we are also sure that LCS is 0;
    
    for(int i=0;i<=l1;i++) LTable[i][0] = 0;
    for(int j=0;j<=l2;j++) LTable[0][j] = 0;
    
//     abcd
//     bcde
//      ''b c d e
//   '' 0 0 0 0 0
//   a  0 0 0 0 0 
//   b  0 1 1 1 1 
//   c  0 1 2 2 2 
//   d  0 1 2 3 3
  
    for(int i=1;i<=l1;i++){
        for(int j=1;j<=l2;j++){
            if(s1[i-1] == s2[j-1])
                LTable[i][j] = 1+LTable[i-1][j-1];
            else LTable[i][j] = max(LTable[i-1][j], LTable[i][j-1]);
        }
    }
    return LTable[l1][l2];
    
}
