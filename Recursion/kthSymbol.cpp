//Link: https://www.scaler.com/academy/mentee-dashboard/classroom/recursion-backtracking-682db75d-7fbd-4d1e-a1fe-6faafd8d77e1/#assignment
int Solution::solve(int A, int B) {
    if(A==1) return 0;
    
    if(B%2==0) return solve(A-1, B/2)==0?1:0;
    return solve(A-1, (B+1)/2);
}
