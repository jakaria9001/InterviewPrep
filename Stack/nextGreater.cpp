
vector<int> Solution::nextGreater(vector<int> &nums) {
    int n = nums.size();
        vector<int> ans(n,-1);
        stack<pair<int,int>> stk;

        for(int ith=0; ith<n; ith++){
            while(!stk.empty() && nums[ith]>stk.top().first){
                ans[stk.top().second] = nums[ith];
                stk.pop();
            }
            stk.push({nums[ith],ith});
        }
        return ans; 

}
