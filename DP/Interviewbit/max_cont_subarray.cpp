// Link: https://www.interviewbit.com/problems/max-sum-contiguous-subarray/
int Solution::maxSubArray(const vector<int> &A) {
    int max_sum = INT_MIN,  curr_sum = 0;
    
    for(int i=0;i<A.size();i++){
        curr_sum += A[i];
        
        if(max_sum < curr_sum) max_sum = curr_sum;
        // max_sum = max(max_sum, curr_sum);
        
        
        if(curr_sum<0){
            curr_sum = 0;
        }
    }
    return max_sum;
}
