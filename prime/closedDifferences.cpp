// Link: https://www.scaler.com/academy/mentee-dashboard/classroom/math-for-quant-2510b433-ae78-4883-91dd-659693c6cf71/#assignment

int Solution::solve(vector<int> &A) {
    int n = A.size();
    if(n==1) return 1;
    
    int gcd = A[0],f = 0;
    for(int x :A){
        gcd = __gcd(gcd,x);
        if(x==0) f=1;
    }
    int ans,mx = *max_element(A.begin(),A.end());
    
    ans = mx/gcd;
    return max(ans+f,n);
}
