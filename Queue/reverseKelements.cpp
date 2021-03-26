// Reversing elements of queue:

vector<int> Solution::solve(vector<int> &A, int B) {
    // B = B%A.size();
    stack<int> q;
    for(int i=0;i<B;i++)
        q.push(A[i]);
    for(int i=0;i<B;i++){
        A[i] = q.top();
        q.pop();
    }
    return A;
}
