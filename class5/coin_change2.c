int minNum(vector<int> S, int m, int n) {
    vector<int> table(n+1, INT::MAX);
    table[0] = 0;
    for(int i = 1; i <= n; i++)
        for(int j = 0; j < m; j++) {
            if( i >= s[j] && table[i] > table[i-s[j]]) 
                table[i] = table[i-s[j]] + 1; 
    }
    return table[n];
}

