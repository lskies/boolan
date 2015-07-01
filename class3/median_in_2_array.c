double helper(int A[], int m, int B[], int n, int k){
    // find the kth largest element
    if(m > n)
        return helper(B, n, A, m, k);//make sure that the second one is the bigger array;
    if(m == 0)
        return B[k - 1];
    if(k == 1){
        return min(A[0], B[0]);
    }
    int pa = min(k / 2, m); // assign k / 2 to each of the array and cut the smaller one
    int pb = k - pa;
    if (A[pa-1] <= B[pb-1])
        return helper(A + pa, m - pa, B, n, k - pa);
    return helper(A, m, B + pb, n - pb, k - pb);
}

double findMedianSortedArrays(int A[], int m, int B[], int n) {
    int total = m + n;
    if(total % 2 == 0){
        return (helper(A, m, B, n, total / 2) + helper(A, m, B, n, total / 2 + 1)) / 2;
    }
    return helper(A, m, B, n, total / 2 + 1);
}

