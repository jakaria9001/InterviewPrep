// Link : https://leetcode.com/problems/min-cost-climbing-stairs/submissions/

class Solution {
public:
    int dp[1005];
    
    int ways(vector<int>& cost, int ind){
        
//         if(ind == n-1 || ind==n-2) return cost[ind];
        
//         if(cost[ind+1]<cost[ind+2]) return cost[ind]+ways(cost, ind+1, n);
        
//         return cost[ind]+ways(cost, ind+2, n);
        if(ind<0) return INT_MAX;
        if(ind==0) return cost[0];
        if(ind==1) return cost[1];
        
        if(dp[ind]!=-1) return dp[ind];
        
        int ans = cost[ind] + min(ways(cost, ind-1), ways(cost, ind-2));
        
        return dp[ind] = ans;
    }
    int minCostClimbingStairs(vector<int>& cost) {
       
        // take it or leave it, min minimum cost from both otion
        
        // dp[i] = min(A[i]+min(dp[i-1],dp[i-2]), )
        memset(dp, -1, sizeof(dp));
        
        // return min(ways(cost, cost.size() - 1), ways(cost, cost.size() - 2));
        
        // iterative : 
        int n = cost.size();
        int idp[n];
        idp[0] = cost[0];
        idp[1] = cost[1];
        
        for(int i=2;i<n;i++){
            idp[i] = cost[i] + min(idp[i-1], idp[i-2]);
        }
        return min(idp[n-2], idp[n-1]);
        
    }
};
