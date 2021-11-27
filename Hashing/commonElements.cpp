// Link: https://www.geeksforgeeks.org/java-program-to-find-common-elements-between-two-arrays/
/*
  Given two integer array A and B of size N and M respectively. Your task is to find all the common elements in both the array.

  NOTE:
  Each element in the result should appear as many times as it shows in both arrays.
  The result can be in any order.
*/
vector<int> Solution::solve(vector<int> &A, vector<int> &B) {
    unordered_map<int, int> mpp;
    for(int x: A) mpp[x]++;

    vector<int> ans;
    for(int y: B){
        // if(mpp.find(y)!=mpp.end()){
        if(mpp[y]!=0){
            ans.push_back(y);
            mpp[y]--;
        }
    }
    return ans;
}
