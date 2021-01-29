// Link : https://www.scaler.com/academy/mentee-dashboard/classroom/sorting-ii-673c2b42-c142-44de-b86a-2fd44f63429f/?status=active#assignment

int Solution::solve(vector<int> &A) {
    sort(A.begin(),A.end());
    int n = A.size();
    if(n==1) return 0;
    
    int ans = 0;
    int mod = 1e9+7;
    
    long first = 0, second = 0;
    for(int i=0;i<n;i++){
        first = (first*2)%mod;
        first = (first+A[i])%mod;
    }
    for(int i=n-1;i>=0;i--){
        second = (second*2)%mod;
        second = (second+A[i])%mod;
    }
    return (second - first + mod)%mod;
    // for(int i=0;i<n-1;i++){
    //     int counter = 0;
    //     for(int j=i+1;j<n;j++){
    //         ans = (ans + ((A[j]-A[i])%mod)*((1<<counter))%mod)%mod;
    //         counter++;
    //     }
    // }
    // return ans;
}
