// Link : https://www.scaler.com/academy/mentee-dashboard/classroom/sorting-df8edddf-f585-4a2a-bea7-59b025d68719/?status=active#homework

void recursiveInsertionSort(vector<int> &A,int n){
    if(n<=1) return;
    
    recursiveInsertionSort(A, n-1);
    
    int l = A[n-1], j = n-2;
    
    while(j>=0 && A[j]>l){
        A[j+1]=A[j];
        j--;
    }
    A[j+1] = l;
}

vector<int> Solution::solve(vector<int> &A) {
    // sort(A.begin(),A.end());
    // return A;
    
    int n = A.size();
    
    // iterative insertion sort:
    /*
    for(int i=0;i<n-1;i++){
        int j = i;
        while(j>=0 && A[j]>A[j+1]){
            swap(A[j],A[j+1]);
            j--;
        }
    }
    return A;
    */
    // recursive insertion sort:
    recursiveInsertionSort(A, n);
    return A;
}
