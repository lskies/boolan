vector<int> findIntersection(vector<int> A, vector<int> B) {
  vector<int> intersection;
  int n1 = A.size();
  int n2 = B.size();
  int i = 0, j = 0;
  while (i < n1 && j < n2) {
      if (A[i] > B[j]) {
          j++;
      } else if (B[j] > A[i]) {
          i++;
      } else {
          intersection.push_back(A[i]);
          i++;
          j++;
      }
  }
  return intersection;
}
