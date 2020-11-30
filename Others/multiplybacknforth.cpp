vector<int> Solution::solve(vector<int> &A) {
    int n = A.size();
    vector<int> result(n);
    for(int i=0;i<n;i++){
        if(i==0){
            result[i]=A[i]*A[i+1];
        }else if(i==n-1){
             result[i]=A[i]*A[i-1];
        }else{
             result[i]=A[i-1]*A[i+1];
        }
    }
    return result;
}
