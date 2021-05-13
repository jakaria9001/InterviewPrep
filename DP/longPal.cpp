string Solution::longestPalindrome(string A) {
    int n = A.length();
    
    bool table[n][n];
    memset(table, 0 , sizeof(table));
    
    int mxLength = 1;
    int start = 0;
    
    for(int i=0;i<n;i++)
        table[i][i] = true;
    for(int i=0;i<n-1;i++)
        if(A[i]==A[i+1]){
            table[i][i+1] = true;
            start = i;
            mxLength = 2;
        }
    
    for(int k=3;k<=n;k++){
        for(int i=0;i<n-k+1;i++){
            int j = i+k-1;
            if(table[i+1][j-1] && A[i]==A[j]){
                table[i][j] = true;
                if(k>mxLength){
                    start = i;
                    mxLength = k;
                }
            }
        }
    }
    string ans = "";
    for(int i=start;i<start+mxLength;i++)
        ans += A[i];
    return ans;
}
