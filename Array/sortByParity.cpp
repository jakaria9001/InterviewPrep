// Link : https://leetcode.com/explore/learn/card/fun-with-arrays/511/in-place-operations/3260/

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        int n = A.size();
        int ev = 0, od = n-1, y=0;
        vector<int> res(n);
        
        for(int a : A){
            if(a&1) res[od--] = a;
            else res[ev++] = a;
        }
        return res; 
    }
};
