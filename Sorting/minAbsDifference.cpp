// Link : https://www.scaler.com/academy/mentee-dashboard/classroom/sorting-df8edddf-f585-4a2a-bea7-59b025d68719/?status=active#assignment

int Solution::solve(vector<int> &A) {
    sort(A.begin(),A.end());
    int ans = INT_MAX;
    for(int i=1;i<A.size();i++)
        ans = min(ans, A[i]-A[i-1]);
    return ans;
}
