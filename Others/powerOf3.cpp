// Link : https://www.scaler.com/academy/mentee-dashboard/classroom/math-for-quant-2510b433-ae78-4883-91dd-659693c6cf71/#homework
int findsmall(int n){
    int temp = 1;
    if(n<=1) return n;
    while(temp<n)
        temp*=3;
    return (temp == n)?temp:temp/3;
}

vector<int> Solution::solve(int A) {
    
    vector<int> ans;
    while(A!=0){
        int x=findsmall(A);
        ans.push_back(x);
        A -= x;
    }
    sort(ans.begin(),ans.end());
    return ans;
    
}
