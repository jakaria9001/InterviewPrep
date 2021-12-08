// https://leetcode.com/problems/intersection-of-two-arrays/

vector<int> Solution::intersect(const vector<int> &A, const vector<int> &B) {
    vector<int> ans;

    int p1 = 0, p2= 0;
    int n = A.size(), m =B.size();

    while(p1< n && p2<m){
        if(A[p1]==B[p2]){
            ans.push_back(A[p1]);
            p1++, p2++;
        }else if(A[p1]<B[p2]){
            p1++;
        }else p2++;
    }
    return ans;
}
