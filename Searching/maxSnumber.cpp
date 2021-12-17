// https://www.geeksforgeeks.org/maximum-subarray-size-subarrays-size-sum-less-k/

#define ll long long int

int bsearch(ll prefixsum[], int n,
                             int k)
{
    // Initialize result
    int ans = -1;
 
    // Do Binary Search for largest
    // subarray size
    int left = 1, right = n;
    while (left <= right)
    {
        int mid = (left + right) / 2;
 
        // Check for all subarrays after mid
        int i;
        for (i = mid; i <= n; i++)
        {
            // Checking if all the subarrays
            //  of a size less than k.
            if (prefixsum[i] - prefixsum[i - mid] > k)
                break;
        }
 
        // All subarrays of size mid have
        // sum less than or equal to k
        if (i == n + 1)
        {
            left = mid + 1;
            ans = mid;
        }
 
        // We found a subarray of size mid
        // with sum greater than k
        else
            right = mid - 1;
    }
    return ans;
}

int Solution::solve(vector<int> &A, int B) {
    int n = A.size();
    ll prefixsum[n + 1];
    memset(prefixsum, 0, sizeof(prefixsum));
 
    // Finding prefix sum of the array.
    for (int i = 0; i < n; i++)
        prefixsum[i + 1] = prefixsum[i] + A[i];
 
    return bsearch(prefixsum, n, B);
}

// other approach:
int ans = n;
    int sum = 0;
    int start = 0;
 
    // Loop till N
    for (int end = 0; end < n; end++)
    {
        sum += A[end];
 
        while (sum > B) {
            sum -= A[start];
            start++;
            ans = min(ans, end - start + 1);
            if (sum == 0)
                break;
        }
        if (sum == 0) {
            ans = -1;
            break;
        }
    }
    return ans;
