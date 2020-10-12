// Link : https://leetcode.com/problems/missing-number

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = 0, n = nums.size();
        int expectedSum = (n*(n+1))/2;
        for(int a : nums)
            sum+=a;
        return expectedSum - sum;
     }
};
