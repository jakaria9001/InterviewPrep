#define mod 1000000007

int Solution::solve(vector<int> &A, int B) {
    long long int count = 0;
    
    int left = 0, right = A.size() - 1;
    
    while(left <= right)
    {
        
        if(A[left] * A[right] < B)
        {
            
            count = (count + 2*(right - left) + 1)%mod;
            
            left++;
            
        }
        
        else
        {
            
            right--;
            
        }
        
    }
    
    return count;

}
