// Link: https://leetcode.com/problems/maximum-product-subarray/

int Solution::maxProduct(const vector<int> &A) {
    // if(A.size()==1) return A[0];
    int max_ending_here = 1;
    int min_ending_here = 1;
    
    int max_so_far = INT_MIN;
    int flag = 0;

    for(int i=0;i<A.size();i++){
        if(A[i]<0){
            swap(max_ending_here, min_ending_here);

        }
        max_ending_here = max(A[i], A[i]*max_ending_here);
        min_ending_here = min(A[i], min_ending_here*A[i]);
        max_so_far = max(max_so_far, max_ending_here);
    }
    return max_so_far;
    // if(!flag || !max_so_far) return 0;
    // return max(0,max_so_far);
}
