// Link: https://www.interviewbit.com/problems/assign-mice-to-holes/
int Solution::mice(vector<int> &mices, vector<int> &holes) {
    int n = mices.size();
    int m = holes.size();
    if (n != m)
        return -1;
     
    // Sort the arrays
    sort(mices.begin(), mices.end());
    sort(holes.begin(), holes.end());
     
    // Finding max difference between
    // ith mice and hole
    int max = 0;
    for(int i = 0; i < n; ++i)
    {
        if (max < abs(mices[i] - holes[i]))
            max = abs(mices[i] - holes[i]);
    }
    return max;
}
