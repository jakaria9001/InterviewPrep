// link : https://leetcode.com/problems/matrix-diagonal-sum/
class Solution {
public:
    int diagonalSum(vector<vector<int>>& a) {
        int n = a.size();
        int sum = 0;
        for(int i=0;i<n;i++){
            sum+= (a[i][i] + a[i][n-i-1]);
            if(i==n-i-1) sum-=a[i][i];
        }
        return sum;
    }
};
