// Link: https://www.geeksforgeeks.org/first-negative-integer-every-window-size-k/

vector<int> Solution::solve(vector<int> &A, int B) {
    queue <int> neg;
    int n = A.size();
    for(int i=0;i<n;i++){
        if(A[i]<0){
            neg.push(i);
        }
    }
    int i=0;
    int j=B-1;
    vector<int> ans;
    for(;j<n;j++,i++){
        while(!neg.empty() && neg.front()<i){
            neg.pop();
        }
        if(neg.empty() || neg.front()>j){
            ans.push_back(0);
        }
        else{
            ans.push_back(A[neg.front()]);
        }
    }
    return ans;
}
