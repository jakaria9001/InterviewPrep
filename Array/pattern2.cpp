vector<vector<int> > Solution::solve(int A) {
    
    /* 3 - 
             1
           2 1
         3 2 1
    */
    vector<vector<int>> ans;
    
    for(int i=1;i<=A;i++){
        vector<int> temp;
        
        for(int j = 1;j<=A-i;j++)
            // cout<<" ";
            temp.push_back(0);
            
            
        for(int j=i;j>=1;j--)
            // cout<<j<<" ";
            temp.push_back(j);
        
        ans.push_back(temp);
        // cout<<endl;
        
    }
    return ans;
}
