// Link : https://leetcode.com/problems/jump-game-iii/submissions/

class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
       
        if(start<0 || start>=arr.size()) return false;
        if(arr[start]==0) return true;
        if(arr[start]==-1) return false;
        
        int forward = start + arr[start];
        int backward = start - arr[start];
        arr[start] = -1;
        return canReach(arr,forward) || canReach(arr, backward);    
        
    }
};
