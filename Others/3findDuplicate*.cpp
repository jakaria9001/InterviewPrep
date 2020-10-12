// Rabbit Problem, striver solved this in utube.
// Link : https://leetcode.com/problems/find-the-duplicate-number/

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // int n = nums.size()-1;
        // int x = (n*(n+1))/2, s = 0;
        // for(int a : nums)
        //     s+=a;
        // return s - x;
        int slow = nums[0], fast = nums[0];
        
        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
        }while(slow!=fast);
        
        slow = nums[0];
        
        while(slow!=fast)
        {
            slow = nums[slow];
            fast = nums[fast];
        }        
        return slow;
    }
};
