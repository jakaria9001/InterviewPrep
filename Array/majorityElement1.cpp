// Link: https://leetcode.com/problems/majority-element/
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int mE = nums[0], count = 1;
        
        for(int i=0;i< nums.size();i++){
            int x = nums[i];
            if(x==mE) count++;
            else count--;
            
            if(count==0){
                mE = x;
                count = 1;
            }
        }
        count=0;
        for(int x: nums){
            if(x==mE) count++;
        }
        if(count>nums.size()/2)
            return mE;
        return -1;
    }
};
