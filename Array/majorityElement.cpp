// Link: https://leetcode.com/problems/majority-element-ii/
class Solution {
public:
    // Boyer Moore Majority Voting algorithm: 
    
    vector<int> majorityElement(vector<int>& nums) {
        
        int x=-1,y=-1,cx=0,cy=0;
        
        for(int n: nums){
            if(n==x) cx++;
            else if(n==y) cy++;
            else if(cx==0) { x = n, cx = 1;}
            else if(cy==0) { y = n, cy = 1;}
            else cx--,cy--;
        }
        cx = 0, cy = 0;
        for(int n: nums){
            if(n==x) cx++;
            else if(n==y) cy++;
        }
        vector<int> ans;
        int n = nums.size();
        // cout<<x<<" "<<y<<" "<<cx<<" "<<cy;
        if(cx > n/3) ans.push_back(x);
        if(cy > n/3) ans.push_back(y);
        return ans;
    }
};
