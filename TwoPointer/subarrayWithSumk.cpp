vector<int> Solution::solve(vector<int> &A, int B) {
    int p1=0,p2=1;
    int cur_sum = A[0];
    int n = A.size();
    
    while( p2<=n){
        
        while(cur_sum>B and p1<p2-1){
            cur_sum -= A[p1];
            p1++;
        }
        if(cur_sum==B){
            vector<int> ans;
            for(int i=p1;i<p2;i++){
                ans.push_back(A[i]);
            }
            return ans;
        }
        
        if(p2<n)
            cur_sum += A[p2];
         
        p2++;
        
    }
    return {-1};
}
