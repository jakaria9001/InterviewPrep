// Link : https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
       
        int ans = 0;
        int minTill = prices[0];
        for(int i=1;i< prices.size();i++){
            if(prices[i]<minTill){
                minTill=prices[i];
            }else{
                ans = max(ans, prices[i] - minTill);
            }
        }
        return ans;
    }
    
};
