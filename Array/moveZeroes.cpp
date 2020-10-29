// Link : https://leetcode.com/explore/learn/card/fun-with-arrays/511/in-place-operations/3157/
// Idea : first implement out-of-place, then convert it to inplace

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        // if(n<=1) return 0;
        
        int y=0, x[n];
        for(int i=0;i<n;i++)
            if(nums[i]!=0){
                nums[y++] = nums[i];
            }
        while(y<n){
            nums[y++]=0;
        }
        // for(int i=0;i<n;i++)
        //     nums[i] = x[i];
            // cout<<a<< " ";
    }
};
