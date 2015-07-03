int trap(int A[], int n) {
    if(n <= 0)  return 0;      
    vector<int> dp(n,0);
        
    int left_max = 0, right_max = 0,water = 0;
        
    for(int i = 0; i < n; i++) {
        dp[i] = left_max; 
        if(A[i] > left_max)
            left_max = A[i];
        }
        
    for(int i = n -1; i >= 0; i--) {
        if(min(right_max,dp[i]) > A[i])
            water += min(right_max,dp[i]) - A[i];
           
        if(A[i] > right_max)
            right_max = A[i];       
    }
    return water;
}
