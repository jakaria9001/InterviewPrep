// https://leetcode.com/problems/k-diff-pairs-in-an-array/

int Solution::solve(vector<int> &nums, int k) {
    sort(nums.begin(),nums.end());
        int n=nums.size();
        int c=0;
     
        unordered_map<int,int>map;
        for(auto x: nums)
            map[x]++;
        
        for(int i=0;i<n;i++)
        {
            if(i>0 && nums[i]==nums[i-1])
                continue;
            
            if(map.find(nums[i]+k)!=map.end())
            {
                if(k==0)
                {
                    if(map[nums[i]]>1)
                        c++;
                }
                else
                    c++;
            }
        }
        
        return c;
}
