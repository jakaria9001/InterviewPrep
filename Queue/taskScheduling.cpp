// FCFS cpp implementation:
// Link : https://www.geeksforgeeks.org/program-for-fcfs-cpu-scheduling-set-1/

int Solution::solve(vector<int> &A, vector<int> &B) {
    queue<int> q;
    for(int x: A){
        q.push(x);
    }
    int ans = 0;
    
    for(int x: B){
        while(!q.empty() && q.front()!=x){
            ans+=1;
            int t = q.front();
            q.push(t);
            q.pop();
        }
        q.pop();
        ans+=1;
    }
    return ans;
}
