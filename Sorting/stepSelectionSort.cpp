// Link : https://www.scaler.com/academy/mentee-dashboard/classroom/sorting-ii-673c2b42-c142-44de-b86a-2fd44f63429f/#homework
vector<int> Solution::solve(vector<int> &A) {
    
    vector<int> ans;
    int min_indx, n =A.size();
    for(int i=0;i<n-1;i++){
        min_indx = i;
        for(int j=i+1;j<n;j++){
            if(A[j]<A[min_indx])
                min_indx = j;
        }
        ans.push_back(min_indx);
        swap(A[i],A[min_indx]);
    }
    return ans;
}
