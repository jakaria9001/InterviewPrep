// Link  : https://leetcode.com/problems/set-matrix-zeroes/submissions/
class Solution {
public:
    void setZeroes(vector<vector<int>>& A) {
    
        // vector< vector < int > > A  = matrix;
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    int n = A.size(), m = A[0].size();
    bool fRow = false;
    // first row
    for(int i=0;i<m;i++)
        if(A[0][i]==0)
            fRow = true;
    // columns with zeros, updated first row.
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(A[i][j]==0)
                A[0][j] = 0;
        }
    }
    
    for(int i=1;i<n;i++){
        // check row with zero
        bool rowWithZero = false;
        
        for(int j=0;j<m;j++)
            if(A[i][j]==0){
                rowWithZero = true;
                break;
            }
        // update row with zero, comparing with the first row.
        for(int j=0;j<m;j++)
            if(rowWithZero || A[0][j]==0)
               A[i][j] = 0;
    }
    // update the first row, if any
    if(fRow)
        for(int i=0;i<m;i++)
            A[0][i] = 0;
    

    }
};
