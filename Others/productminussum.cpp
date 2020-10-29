// Link : https://leetcode.com/problems/subtract-the-product-and-sum-of-digits-of-an-integer/

class Solution {
public:
    int subtractProductAndSum(int n) {
        int m = n,prod = 1, sum =0;
        while(m>0){
            int digit = m%10;
            prod*=digit;
            sum+=digit;
            m/=10;
        }
        return prod - sum;
    }
};
