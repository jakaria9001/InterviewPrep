
// Link: https://www.geeksforgeeks.org/nearly-sorted-algorithm/
vector<int> Solution::solve(vector<int> &arr, int k) {
    // sort(A.begin(), A.end());
    // return A;

    int size;
    int n = arr.size();
    size=(n==k)?k:k+1;
    priority_queue<int, vector<int>, greater<int> > pq(arr.begin(), arr.end());
    
    vector<int> ans(n);
    // i is index for remaining elements in arr[] and index
    // is target index of for current minimum element in
    // Min Heap 'pq'.
    int index = 0;
    for (int i = k + 1; i < n; i++) {
        arr[index++] = pq.top();
        pq.pop();
        pq.push(arr[i]);
    }
 
    while (pq.empty() == false) {
        arr[index++] = pq.top();
        pq.pop();
    }
    return arr;
}
