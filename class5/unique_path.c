int uniquePathsBackTrack(int m, int n) {
    if(m==1 || n==1) return 1;
    return uniquePaths(m-1, n) + uniquePaths(m, n-1);
}

int uniquePaths(int m, int n) 
{
    vector<vector<int> > table(m, vector<int>(n, 1));
    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            table[i][j] = table[i-1][j] + table[i][j-1];
        }
    }
    return table[m-1][n-1];
}
//Save space
int uniquePaths2(int m, int n)
{
    vector<int> table(n, 1);
    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            table[j] += table[j-1];
        }
    }
    return table[n-1];
}
