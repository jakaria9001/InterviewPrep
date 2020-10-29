// Link : https://leetcode.com/explore/learn/card/fun-with-arrays/511/in-place-operations/3258/

class Solution {
public:
    int removeDuplicates(vector<int>& arr) {
        
        int n = arr.size();
        if(n<=1) return n;
        
        int j = 0; 
        for(int i=0;i<n-1;i++){
            if(arr[i]!=arr[i+1])
                arr[j++] = arr[i];
        }
        arr[j++] = arr[n-1];
        return j;
    }
};
