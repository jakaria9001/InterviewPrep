// Link : https://www.scaler.com/academy/mentee-dashboard/classroom/sorting-df8edddf-f585-4a2a-bea7-59b025d68719/?status=active#assignment

int Solution::solve(vector<int> &A) {
    int n = A.size();
    int c = 0;
    for(int i=0;i<n-1;i++){
        int j=i;
        while(j>=0 && A[j]>A[j+1]){
            swap(A[j],A[j+1]);
            j--;
            c++;
        }
    }
    return c;
}
