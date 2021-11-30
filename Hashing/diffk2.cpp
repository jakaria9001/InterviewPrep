// Link: https://www.interviewbit.com/problems/diffk-ii/
// Given an array A of integers and another non negative integer k, find if there exists 2 indices i and j such that A[i] - A[j] = k, i != j.
int Solution::diffPossible(const vector<int> &A, int B) {
    if (A.size() < 2 || B < 0) 
        return 0;
        
    int n = A.size();
    // O(n^2)-O(1) solution: 
    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
            if(abs(A[i]-A[j]) == B) return 1;
    // O(n)-O(n) solution:
    unordered_set<int> st;
    for(int x: A){
        int Ai = x+B;
        int Aj = x-B;

        if(st.find(Ai)!=st.end() || st.find(Aj)!=st.end()) return 1;

        st.insert(x);   
    }
    return 0;
}
