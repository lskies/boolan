int uniquePaths(int m, int n) {
    int ways[n] = {0};
    
    ways[n-1] = 1;
    for(int i = m - 1; i >= 0; --i)
        for(int j = n - 2; j >= 0; --j )
            ways[j] += ways[j+1];
    return ways[0];
}
