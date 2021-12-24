int Solution::numDistinct(string s, string t) {
    int n = s.length();
        int m = t.length();
        vector<vector<int>> pos(256,vector<int>{});
        vector<long long> count(m+1,0);
        count[0] = 1;
        // For each character in target save the position
        // Save point in reverse order to avoid acumulation in the same turn
        for(int i=m-1; i>=0; i--)
        {
            pos[t[i]].push_back(i);
        }
        // Update next counters
        for(int i=0; i<n; i++)
        {
            for(auto p: pos[s[i]])
            {
               if (p>i || m-p > n-i) continue;
               count[p+1] += count[p];
               // cout << p+1 << ", " << count[p+1] << endl;
            }
        }
		return (count[m] > INT_MAX)?-1:count[m];
}
