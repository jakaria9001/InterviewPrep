// Link: https://www.interviewbit.com/problems/pairs-with-given-xor/
int Solution::solve(vector<int> &arr, int x) {
    // unordered_map<int, int> mpp;
    int n = arr.size();
    int result = 0; // Initialize result
 
    // create empty map that stores counts of
    // individual elements of array.
    unordered_map<int, int> m;
 
    for (int i=0; i<n ; i++)
    {
        int curr_xor =  x^arr[i];
 
        // If there exist an element in map m
        // with XOR equals to x^arr[i], that means
        // there exist an element such that the
        // XOR of element with arr[i] is equal to
        // x, then increment count.
        if (m.find(curr_xor) != m.end())
            result += m[curr_xor];
 
        // Increment count of current element
        m[arr[i]]++;
    }
 
 
    // return total count of pairs with XOR equal to x
    return result;
}
