//find duplicate: 
// Link : https://leetcode.com/problems/contains-duplicate-ii/

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        
        // for(int i=0;i<=nums.size();i++){
        //     for(int j=i;j<=i+k;j++){
        //         // if(i<0 || j<0) continue;
        //         if(j==nums.size()) return false;
        //         if(nums[i]==nums[j] && i!=j)
        //             return true;
        //     }
        // }
        
        unordered_map<int,int> m;
        unordered_map<int,int>::iterator it;
        
        
        for(int i=0; i<nums.size(); ++i) {
            it = m.find(nums[i]);
            if(it != m.end() and i - it->second <= k) return true;
            else m[nums[i]] = i;
        }
        return false;
    }
};
