
// ref: https://youtu.be/IjaP8qt1IYI

int peak(vector<int> &arr, int l, int r){
    if(l>r) return -1;
    int mid = (l+r)/2;
    
    if(arr[mid] > arr[mid-1] && arr[mid]>arr[mid+1]) return mid;
    if(arr[mid] > arr[mid-1] && arr[mid]<arr[mid+1]) return peak(arr, mid+1, r);
    return peak(arr, l,mid-1);
    
}

int BS(vector<int> &arr, int low, int high, int target, int dir){
    
    int mid;
    
    if(dir == 1){
        while(low<=high){
            mid = (low+high)/2;
            if(arr[mid] == target) return mid;
            
            if(target < arr[mid] ) high = mid-1;
            
            else low = mid+1;
        }    
    }else {
        
        while (low <= high) {
            mid = (low+high) / 2;
            if (target == arr[mid]) return mid;
            else if (target < arr[mid]) 
                low = mid + 1;
            else
                high = mid - 1;
        }
    }
    return -1;
}
int Solution::solve(vector<int> &arr, int B) {
    
    // for(int i=0;i<A.size();i++) if(A[i]==B) return i; O(n)
    int n = arr.size();
    int peak_index = peak(arr,0,n-1);
    
    int ans = BS(arr, 0, peak_index-1,B, 1);
    ans = max(ans, BS(arr,peak_index, n-1,B, -1));
    
    return ans; /// O(log2n)
}
