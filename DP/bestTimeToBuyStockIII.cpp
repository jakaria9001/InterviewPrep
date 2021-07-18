// Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/submissions/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n==1) return 0;
        int left_max[n], right_max[n];
        left_max[0] = 0, right_max[n-1] = 0;
        int lmx = 0, lmin=prices[0];
        for(int i=1;i<n;i++){
            if(prices[i]<lmin){
                lmin = prices[i];
            }else{
                lmx = max(lmx, prices[i]-lmin);    
            }            
            left_max[i] = lmx;
        }
        int rmx = 0, rmax = prices[n-1];
        for(int i=n-2;i>=0;i--){
            if(prices[i]>rmax){
                rmax = prices[i];
            }else{
                rmx = max(rmx, rmax-prices[i]);
            }
            right_max[i] = rmx;
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            ans = max(ans, left_max[i]+right_max[i]);
        }
        return ans;
        // for(int i=0;i<n;i++) cout<<left_max[i]<<" ";
        // cout<<endl;
        // for(int i=0;i<n;i++) cout<<right_max[i]<<" ";
        
        return 0;
    }
};
