// Link : https://leetcode.com/problems/single-number/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int xorv = 0;
        for(int a : nums)
            xorv = xorv xor a;
        return xorv;
    }
};
