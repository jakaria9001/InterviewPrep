// Link : https://www.scaler.com/academy/mentee-dashboard/classroom/greedy-1/#homework - The SHIP Company
vector<int> Solution::solve(int A, int B, vector<int> &C) {
    
    int maxm = 0, minm = 0;
    vector<int> temp = C;
    int noOfPassRem = A;
    
    // find minm : 
    sort(temp.begin(), temp.end());
    for(int x : temp){
        
        while(x>0 && noOfPassRem>0){
            minm += x;
            x--,noOfPassRem--;
        }
        if(noOfPassRem == 0) break;
    }
    // find maxm : reverse sort at every instant and get the value of last element
    noOfPassRem = A;
    
    
    while(noOfPassRem > 0){
        sort(temp.begin(), temp.end(), greater<int>());
        maxm += temp[0];
        temp[0] -= 1;
        noOfPassRem--;
    }
    
    return {maxm, minm};
}
