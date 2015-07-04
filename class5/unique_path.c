int dp(int m, int n) {
    int mat[M_MAX+2][N_MAX+2] = {0};
    mat[m][n+1] = 1;

    for (int r = m; r >= 1; r--)
        for (int c = n; c >= 1; c--)
            mat[r][c] = mat[r+1][c] + mat[r][c+1];

    return mat[1][1];
}
