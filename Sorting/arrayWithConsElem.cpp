// Link : https://www.scaler.com/academy/mentee-dashboard/classroom/sorting-df8edddf-f585-4a2a-bea7-59b025d68719/?status=active#assignment

int Solution::solve(vector<int> &A) {
    sort(A.begin(),A.end());
    for(int i=1;i<A.size();i++)
        if(A[i]-A[i-1] != 1)
            return 0;
    return 1;
}
