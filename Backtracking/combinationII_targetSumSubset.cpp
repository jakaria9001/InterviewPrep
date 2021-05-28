// Link : https://leetcode.com/problems/combination-sum-ii/
void subSetSum(vector<vector<int>>& ans, int ind, int k,vector<int> &A, vector<int> &temp){
    if(k==0){
        ans.push_back(temp);
        return;
    }else{
        for(int i=ind;i<A.size();i++){
            
            if(A[i]>k) return;
            if(i && i>ind && A[i]==A[i-1]) continue;
        
            temp.push_back(A[i]);
            subSetSum(ans,i+1, k-A[i], A, temp);
            temp.pop_back();
        }
    }
    
}
  
vector<vector<int> > Solution::combinationSum(vector<int> &A, int B) {

    vector<int> temp;
    int ind = 0;
    vector<vector<int>> ans;
    sort(A.begin(),A.end());
    subSetSum(ans,ind, B, A, temp);
    
    return ans;
    
}
