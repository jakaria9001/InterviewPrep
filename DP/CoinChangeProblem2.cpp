// Link : https://www.interviewbit.com/problems/coin-sum-infinite/

int mod = 1e6+7;

int Solution::coinchange2(vector<int> &A, int N) {
    long long int num_ways[N + 1];
        int i, j, m = A.size();

        // Initialise all values with 0
        memset(num_ways, 0, sizeof(num_ways));

        // Base case (If required sum is 0)
        num_ways[0] = 1;

        // Pick all coins one by one and update the num_ways[] values
        for (i = 0; i < m; i++) {
            for (j = A[i]; j <= N; j++) {
                num_ways[j] = (num_ways[j]+num_ways[j - A[i]])%mod;
            }
        }
    return num_ways[N];
}
