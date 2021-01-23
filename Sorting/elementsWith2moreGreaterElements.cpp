// Link : https://www.scaler.com/academy/mentee-dashboard/classroom/sorting-df8edddf-f585-4a2a-bea7-59b025d68719/?status=active#assignment

vector<int> Solution::solve(vector<int> &A) {
    // sort(A.begin(), A.end());
    vector<int> ans;
    
    int first = INT_MIN, second =INT_MIN;
 
    // find the largest element
    for (int i = 0; i < A.size(); i++) {
        if(A[i]>first){
            second = first;
            first = A[i];
        }else if(A[i]>second)
            second = A[i];
    }
 
    for(int x : A)
        if(x<second)
            ans.push_back(x);
    return ans;
    
}
