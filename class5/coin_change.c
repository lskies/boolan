int countWays(vector<int> S, int m, int n) {
    vector<int> table(n+1, 0);
    table[0] = 1;
    for(int i = 1; i <= n; i++)
        for(int j = 0; j < m; j++)
            table[i] += (i-s[j] >= 0) ? table[i-S[j]] : 0;
    return table[n];
}

