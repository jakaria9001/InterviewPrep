// Link : https://leetcode.com/problems/house-robber/submissions/

class Solution {
public:
    int maxMoney(vector<int> arr, int n, int i){
        if(i==0) return arr[0];
        if(i==1) return max(arr[0],arr[1]);
        
        return max(maxMoney(arr, n, i-1), arr[i]+maxMoney(n, i-2));
        
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(nums.size()==1) return nums[0];
        // int res = maxMoney(nums, n, i); //recursive soln
        // return 1;
        int dp[n];
        // memset()
        dp[0] = nums[0];
        if(n>0) dp[1] = max(nums[0], nums[1]);
        
        for(int i=2;i<n;i++){
            dp[i] = max(nums[i]+dp[i-2], dp[i-1]);
        }
        
        return dp[n-1];
    }
};
