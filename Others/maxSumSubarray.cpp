// Given an integer array nums, find the contiguous subarray (containing at least one number)  which has the largest sum and return its sum.
// Link : https://leetcode.com/problems/maximum-subarray
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int sum = 0, ans =INT_MIN;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            ans = max(ans,sum);

            if(sum<0) sum = 0;
            
            
        }
        return ans;
    }
};
