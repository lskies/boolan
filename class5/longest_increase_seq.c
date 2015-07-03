int longestIncreasingSubsequence( int arr[], int n) {
    vector<int> maxLength(n, 1);
    int global_max = 0;
    for (int i = 0; i < n; i++)   
        for(int j = 0; j < i; j++) 
            if ( arr[i] > arr[j] && maxLength[j] + 1 > maxLength[i] )
                maxLength[i] = maxLength[j] + 1;

    for(int i = 0; i < n; i++)
        if ( global_max < maxLength[i] )
            global_max = maxLength[i];

    return global_max;
}
