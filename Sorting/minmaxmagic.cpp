// Link: https://www.scaler.com/academy/mentee-dashboard/classroom/sorting-ii-673c2b42-c142-44de-b86a-2fd44f63429f/#homework

#define mod (int)1000000007

vector<int> Solution::solve(vector<int> &A) {
    sort(A.begin(), A.end());
    vector<int> ans(2,0);
    int n = A.size();
    long long int mx = 0, mn = 0;
    for(int i=1;i<n;i+=2)
        mn += ((A[i]-A[i-1]))%mod;
    for(int i=0;i<n/2;i++)
        mx += ((A[n-i-1]-A[i]))%mod;
    ans[0] = (mx)%mod, ans[1] = (mn)%mod;
    return ans;
}
