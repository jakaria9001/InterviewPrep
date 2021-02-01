// Link : https://www.scaler.com/academy/mentee-dashboard/classroom/sorting-ii-673c2b42-c142-44de-b86a-2fd44f63429f/#homework

int Solution::solve(vector<int> &A) {
    int n = A.size();
    vector<int> maxOfLeft(n), minOfRight(n);
    maxOfLeft[0] = A[0];
    for(int i=1;i<n;i++)
        maxOfLeft[i] = max(maxOfLeft[i-1], A[i]);
    minOfRight[n-1] = A[n-1];
    for(int i=n-2;i>=0;i--)
        minOfRight[i] = min(minOfRight[i+1],A[i]);
    int count = 1;
    for(int i=0;i<n-1;i++)
        count += (minOfRight[i+1]>=maxOfLeft[i]);
    return count;
}
