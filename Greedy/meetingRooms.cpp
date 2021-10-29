// Link : https://www.interviewbit.com/problems/meeting-rooms/

int Solution::solve(vector<vector<int> > &A) {
    int n = A.size();
    vector<int> start(n), end(n);
    for(int i=0;i<n;i++){
        start[i] = A[i][0];
        end[i] = A[i][1];
    }
    sort(start.begin(), start.end());
    sort(end.begin(), end.end());

    int i = 0, j = 0;
        int activate = 0, ans = 0;
        while(i < n && j < n){
            if(start[i] < end[j]){
                activate++;
                i++;
            }else{
                activate--;
                j++;
            }
            ans = max(ans, activate);
        }
        return ans;
}
