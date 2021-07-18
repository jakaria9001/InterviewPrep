// Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/submissions/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        int ans=0;
        
        for(int i=1;i<n;i++){
            ans += max(prices[i]-prices[i-1],0);
        }
        return ans;
        
        // if(n==1) return 0;
        // int dp[n];
        // dp[0] = max(0,prices[1]-prices[0]);
        // for(int i=1;i<n;i++){
        //     int ans = 0;
        //     for(int j=1;j<i;j++){
        //         ans = max(ans, prices[i]-prices[j] + dp[j-1]);
        //     }
        //     dp[i] = max(dp[i-1], ans);
        // }
        // return dp[n-1];
    }
};
