// Link : https://www.scaler.com/academy/mentee-dashboard/classroom/math-for-quant-2510b433-ae78-4883-91dd-659693c6cf71/#assignment

vector<int> Solution::solve(vector<int> &A) {
    int mn = INT_MAX, mnc = 0;
    for(int a:A){
        if(a<mn){
            mn = a;
            mnc = 1;
        }else if(a==mn) mnc++;
    }
    int x = mnc, y = A.size();
    int d = __gcd(x,y);
    vector<int> ans(2);
    ans[0] = x/d;
    ans[1] = y/d;
    
    return ans;
}
