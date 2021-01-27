// Link : scaler.com/academy/mentee-dashboard/classroom/sorting-df8edddf-f585-4a2a-bea7-59b025d68719/?status=active#homework

int Solution::solve(vector<int> &A) {
    int n = A.size();
    sort(A.begin(),A.end(), greater<int>());
    int ans = A[0];
    for(int i=1;i<n;i++)
        if(A[i]!=ans)
            return A[i];
    return 0;
    // int first = A[0], second = A[0];
    
    // for(int i=0;i<n;i++){
    //     if(A[i]>first){
    //         second = first;
    //         first = A[i];
    //     }else if(A[i]>second)
    //         second = A[i];
    // }
    // if(first == second) return 0;
    // return second;
}
