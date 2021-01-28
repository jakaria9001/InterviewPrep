// Imp Qstion,  Link : https://www.scaler.com/academy/mentee-dashboard/classroom/sorting-df8edddf-f585-4a2a-bea7-59b025d68719/?status=active#homework

vector<int> Solution::solve(vector<int> &A) {
    int n =A.size();
    for(int i=0;i<n;i++){
        if(i%2==0){
            if(A[i]>=0){
                int k = i+1;
                while(k<n && A[k]>=0)
                    k++;
                if(k==n) break;
                for(int j=k;j>i;j--)
                    swap(A[j],A[j-1]);
                
            }
        }else {
            if(A[i]<0){
                int k = i+1;
                while(k<n && A[k]<0)    
                    k++;
                if(k>=n) break;
                for(int j=k;j>i;j--)
                    swap(A[j],A[j-1]);
            }
        }
    }
    return A;
}


