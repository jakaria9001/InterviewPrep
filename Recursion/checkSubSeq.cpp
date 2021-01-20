// Link  : https://www.scaler.com/academy/mentee-dashboard/classroom/recursion-backtracking-682db75d-7fbd-4d1e-a1fe-6faafd8d77e1/#assignment

bool check(string A, string B, int m, int n){
    
    int j = 0;
    for(int i=0;i<n&&j<m;i++)
        if(A[j]==B[i])
            j++;
            
    return (j==m); 
    // if(m==0) return true;
    // if(n==0) return false;
    // if(A[m-1]==B[n-1])
    //     return check(A,B,m-1,n-1);
    // return check(A,B,m,n-1);
}

int Solution::solve(string A, string B) {
    int m = A.length(), n = B.length();
    bool ans = check(A,B, m,n);
    if(ans) return 1;
    return 0;
}
