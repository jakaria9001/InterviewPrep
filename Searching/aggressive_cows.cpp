// link : https://www.scaler.com/academy/mentee-dashboard/classroom/searching-iii/#assignment

bool check(vector<int> stalls, int n, int k, int minDist){
    int recently_placed = stalls[0];
    int cows_placed = 1;
    for(int i=1;i<n;i++){
        if(stalls[i]-recently_placed >=minDist){
            recently_placed = stalls[i];
            cows_placed++;
        }
    }
    return (cows_placed >= k);
}

int Solution::solve(vector<int> &A, int B) {
    int n = A.size();
    sort(A.begin(),A.end());
    int ans,low = 1, high = A[n-1]-A[0];
    while(low<=high){
        int mid = low+(high-low)/2;
        if(check(A,n,B,mid)){
            ans = mid;
            low = mid+1;
        }else high = mid - 1;
    }
    return ans;
}
