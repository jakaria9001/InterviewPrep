// Statement: 
/*

Hotel Occurrences
Problem Description

You are given an array A, consisting of the street numbers of hotels your friend has visited. Every street has just one hotel. Your friend can visit a hotel multiple times too.

You are supposed to make another array, that stores the indices of the hotels your friend has visited. The array should ignore the multiple visits to each hotel, and should only consider the last visit made to that hotel.

The array elements should be in order of visiting the hotels.



Problem Constraints
1 <= size(A) <= 50
1 <= Integer in A <= 1000



Input Format
First argument is an integer array A denoting the indices of the hotel he has visited.



Output Format
Return an integer array consisting of the hotels visited.



Example Input
Input 1:

 A = [1, 2, 3, 2, 5, 3, 2, 4]
Input 2:

 A = [1, 2, 3, 4]


Example Output
Output 1:

 [1, 5, 3, 2, 4]
Output 2:

 [1, 2, 3, 4]

*/

// Solution: 
vector<int> Solution::solve(vector<int> &A) {
    int n = A.size();
    unordered_set<int> ss;
    vector<int> ans;
    
    for(int i=n-1;i>=0;i--){
        if(ss.find(A[i])==ss.end()){
            ans.push_back(A[i]);
            ss.insert(A[i]);
        }
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
