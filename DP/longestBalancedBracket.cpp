int Solution::LBSlength(const string A) {
    int n=A.size(),maxlen=0;
    // cout<<A.size(); if(A.size()<2) {//cout<<A.size(); return 0;}

    //cout<<n<<endl;
    vector<int> dp(n+1,0);
    dp.clear();
    for(int i=0;i<n;i++){
        if(A[i]=='(' or A[i]=='<' or A[i]=='{' or A[i]=='[')
            continue;
        else{
            if(i>0 and dp[i-1]!=0){
                int ind = i-dp[i-1]-1;
                if(((A[ind]=='(' and A[i]==')') or (A[ind]=='<' and A[i]=='>') or (A[ind]=='[' and A[i]==']') or (A[ind]=='{' and A[i]=='}')))
                    dp[i]=dp[i-1]+2+dp[ind-1];
                maxlen = max(maxlen,dp[i]);
            }
            else{
                        if(i>0 and dp[i-1]==0){
                int ind = i-1;
                if(((A[ind]=='(' and A[i]==')') or (A[ind]=='<' and A[i]=='>') or (A[ind]=='[' and A[i]==']') or (A[ind]=='{' and A[i]=='}')))
                    dp[i]=dp[i-2]+2;
                maxlen = max(maxlen,dp[i]);
            }
                }
            }
        }

    // for(int i=0;i<n;i++)
    //     cout<<dp[i]<<" ";
    // cout<<endl;
    return maxlen;
}
