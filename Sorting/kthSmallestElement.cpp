// Link: https://www.scaler.com/academy/mentee-dashboard/classroom/sorting-df8edddf-f585-4a2a-bea7-59b025d68719/?status=active#assignment
int Solution::kthsmallest(const vector<int> &A, int B) {
    vector<int> a = A;
    
    sort(a.begin(),a.end());
    return a[B-1];
}
