// Link : https://leetcode.com/problems/reverse-pairs/submissions/

class Solution {
public:
//     int merge(vector<int> &arr, vector<int> &temp, int left,int mid, int right){
//         int i=left, j=mid, k = left;
//         int count = 0;
//         while(i<mid && j<=right){
//             if(arr[i]<arr[j]){
//                 temp[k++]=arr[i++];
//             }else {
//                 if(arr[i] >= 2*arr[j])
//                     count++;
//                 temp[k++] = arr[j++];
//             }
//         }
//         while(i<mid) temp[k++] = arr[i++];
//         while(j<=right) temp[k++] = arr[j++];
        
//         for(int i=left;i<=right;i++)
//                 arr[i] = temp[i];
//         return count;
//     }
//     int mergesort(vector<int> &arr, vector<int> &temp, int left, int right){
//         int ans = 0;
//         if(left<right){
//             int mid = left+(right-left)/2;
//             ans += mergesort(arr, temp,left, mid);
//             ans += mergesort(arr, temp,mid+1, right);
            
//             ans += merge(arr,temp,left, mid, right);
//         }
//         return ans;
//     }
    int mergeSort(vector<int> &nums, int s, int e){
        if(s == e || s + 1 == e){
            return 0;
        }
        
        int m = s + (e - s)/2;
        int left = mergeSort(nums,s,m);
        int right = mergeSort(nums,m,e);
        
        int start = s;
        int res = 0;
        for(int i = m; i < e; ++i){
            while(start < m && ((long long)nums[start]) <= nums[i]*2LL){
                start++;
            }
            
            res += m - start;
        }
        
        inplace_merge(begin(nums) + s, begin(nums) + m, begin(nums) + e);
        return res + left + right;
    }
    int reversePairs(vector<int>& nums) {
        
        return mergeSort(nums, 0, nums.size());
        
    }
};
