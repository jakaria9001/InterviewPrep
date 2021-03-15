// Link : https://www.scaler.com/academy/mentee-dashboard/classroom/stacks-1/#assignment

int Solution::solve(vector<int> &A) {
    // vector<int> B;
    stack<int> C;
    int n = A.size(), k=0;
    for(int i=0;i<n;i++){
        
        while(C.size() && C.top()==k+1){
            k++;
            C.pop();
        }
        if(A[i]!=k+1)
            C.push(A[i]);
        else k++;
    }
    while(C.size() && C.top()==k+1){
            k++;
            C.pop();
    }
    if(k==n) return 1;
    return 0;
    
}
