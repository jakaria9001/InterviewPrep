// Link : https://leetcode.com/problems/pascals-triangle/submissions/
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
    
    int A = numRows;
    vector<vector<int> > ans;
    if(A==0) return ans;
    
    vector<int> firstRow;
    firstRow.push_back(1);
    
    ans.push_back(firstRow);
        
    for(int i=1;i<A;i++){
        vector<int> prevRow = ans[i-1];
        vector<int> currRow;
        
        currRow.push_back(1);
        
        for(int j=1;j<i;j++){
            currRow.push_back(prevRow[j-1]+prevRow[j]);
        }
        
        currRow.push_back(1);
        
        ans.push_back(currRow);
    }
    
    return ans;
}

};
