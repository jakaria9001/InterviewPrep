// Tennis Logs
// Link : https://www.scaler.com/academy/mentee-dashboard/classroom/greedy-1/#homework

string Solution::solve(int A, vector<int> &B) {
    int prevLoser = 3;
    string t = "Yes", f = "No";
    
    for(int x : B){
        if(x == prevLoser) return f;
        prevLoser = 6 - (x+prevLoser);
    }
    return t;
}
