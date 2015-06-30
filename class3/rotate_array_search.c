int rotated_binary_search(int A[], int N, int key) {
  int L = 0;
  int R = N - 1;

  while (L <= R) {
    // Avoid overflow, same as M=(L+R)/2
    int M = L + ((R - L) >> 1);
    if (A[M] == key) return M;

    // the bottom half is sorted
    if (A[L] <= A[M]) {
      if (A[L] <= key && key < A[M])
        R = M - 1;
      else
        L = M + 1;
    }
    // the upper half is sorted
    else {
      if (A[M] < key && key <= A[R])
        L = M + 1;
      else
        R = M - 1;
    }
  }
  return -1;
}
