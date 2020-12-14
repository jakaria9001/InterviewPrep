// Link : https://www.scaler.com/academy/mentee-dashboard/classroom/2d-arrays-ff925e56-1029-4935-90b8-a9e4bf0186f9/
int Solution::solve(vector<vector<int> > &A) {
    
    int n = A.size() , m = A[0].size();
    int ans = 0, result=0;
    for(int i=m-1; i>=0;i--)
        if(A[0][i]==1)
            ans++;
        else break;
    
    for(int i=1;i<n;i++){
        int temp = 0;
        for(int j=m-1;j>=0;j--)
            if(A[i][j]==1)
                temp++;
            else break; 
        if(temp>ans){
            result = i;
            ans = temp;
        } 
    }
    
    return result ;
    
}
