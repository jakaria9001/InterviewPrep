// Link : https://leetcode.com/problems/range-sum-query-immutable/
class NumArray {
    vector<int> numbers;
    // vector<int>
public:
    NumArray(vector<int>& nums) {
        numbers = nums;
        numbers[0] = nums[0];
        for(int i=1;i<nums.size();i++)
            numbers[i] = numbers[i-1]+nums[i];
    }
    
    int sumRange(int left, int right) {
        if(left == 0) return numbers[right];
        return numbers[right]-numbers[left-1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
