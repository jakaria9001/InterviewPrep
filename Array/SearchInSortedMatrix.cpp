// Link : https://www.scaler.com/academy/mentee-dashboard/classroom/2d-arrays-ff925e56-1029-4935-90b8-a9e4bf0186f9/#homework%2F4092
int Solution::solve(vector<vector<int> > &A, int B) {
    int n=A.size(), m = A[0].size();
    /*
    // O(n^m):
    for(int i=0;i<n;i++){
        
        for(int j=0;j<m;j++){
            if(A[i][j]==B){
                return  (i+1) * 1009 + (j+1);
            }
        }
    }
    return -1;*/
    
    // Alternate : O(n+m)
    int i = 0, j = m-1;
    while(i<n && j>=0){
        if(A[i][j]==B)
            return (i+1) * 1009 + (j+1);
        else if(A[i][j]>B)
            j--;
        else i++;
    }
    return -1;
    
}
