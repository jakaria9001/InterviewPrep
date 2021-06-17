// Link : https://leetcode.com/problems/edit-distance/
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.length(), m = word2.length();
    
        int dp[n+1][m+1];
        
        // if(l1==0) return l2, insert all chars of s2
        // if(l2==0) return l1, delete all chars of s1
        
        for(int i=0;i<=n;i++) dp[i][0] = i;
        for(int j=0;j<=m;j++) dp[0][j] = j;
        
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                if(word1[i-1]==word2[j-1]) 
                    dp[i][j] = dp[i-1][j-1];
                else dp[i][j] = 1+ min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]));
        
        return dp[n][m];
    }
};

/*
// O(N) space : 
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        vector<int> pre(n + 1, 0), cur(n + 1, 0);
        for (int j = 1; j <= n; j++) {
            pre[j] = j;
        }
        for (int i = 1; i <= m; i++) {
            cur[0] = i;
            for (int j = 1; j <= n; j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    cur[j] = pre[j - 1];
                } else {
                    cur[j] = min(pre[j - 1], min(cur[j - 1], pre[j])) + 1;
                }
            }
            fill(pre.begin(), pre.end(), 0);
            swap(pre, cur);
        }
        return pre[n];
    }
};
*/
