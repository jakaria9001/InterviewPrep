int Solution::solve(int A) {
    int coinIndx = 0, mxVal = 1;
    while(A >= mxVal){
        mxVal *= 5;
        coinIndx++;
    }
    // cout<<mxVal <<" ";
    int ans = 0;
    while(A>0 && mxVal >=0){
        
        int x = A%mxVal;
        int y = A/mxVal;
        
        ans += y;
        A = x;
        mxVal/=5;
    }
    return ans;
}
