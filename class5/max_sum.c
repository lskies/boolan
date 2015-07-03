int maxSubArray(int A[], int n) {
    if(n <= 0)  return 0;
    int max_sum = A[0], sum = A[0];
    for(int i = 1; i < n; i++){
        sum = max(sum + A[i], A[i]);
        if(sum > max_sum)
            max_sum = sum;
    }
    return max_sum;
}

