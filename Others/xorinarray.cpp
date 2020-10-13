
// Link : https://leetcode.com/problems/xor-operation-in-an-array/submissions/

class Solution {
public:
    int xorOperation(int n, int start) {
        int xora = 0;
        // int arr[n];
        for(int i=0;i<n;i++){
            int x = start + 2*i;
            xora = xora xor x;
        }
        
        // int y = n*start + n*(n+1)/2
            
        return xora;
    }
};
