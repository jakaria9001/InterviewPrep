/*
Problem Description

Given an array A, find the nearest smaller element G[i] for every element A[i] in the array such that the element has an index smaller than i.

More formally,

G[i] for an element A[i] = an element A[j] such that

j is maximum possible AND

j < i AND

A[j] < A[i]

Elements for which no smaller element exist, consider next smaller element as -1.

Input Format
The only argument given is integer array A.



Output Format
Return the integar array G such that G[i] contains nearest smaller number than A[i].If no such element occurs G[i] should be -1.



Example Input
Input 1:

 A = [4, 5, 2, 10, 8]
Input 2:

 A = [3, 2, 1]


Example Output
Output 1:

[-1, 4, -1, 2, 2]
Output 2:

 [-1, -1, -1]
*/

vector<int> Solution::prevSmaller(vector<int> &A) {
    int n = A.size();
    vector<int> ans(n, -1);
    
    stack<int> st;
    for(int i=0;i<n;i++){
        
            while(!st.empty() and st.top()>=A[i]){
                st.pop();
            }
        if(!st.empty()) ans[i] = st.top();
        
        st.push(A[i]);
    }
    return ans;
}
