Set A[n] = {2, 11, 54, 87, 99}
Set B[2*n] = = {4, 9, 34, 67, 98, 0, 0, 0, 0, 0}
void Merge(int A[], int B[], int size_b,  int n) {
    indexA=n -1;
    indexB=n -1;
    index_new=2n -1;
    while (index_new >= 0) {
        if (A[indexA] < B[indexB]) {
            B[index_new] = B[indexB];
            indexB--;
            index_new--;
        }
        else {
            B[index_new] = A[indexA];
            indexA--;
            index_new--;
        }

        // Optimization if A or B can be directly copied
        if (indexB == -1) {
            while(index_new >= 0)
                B[index_new--] = A[indexA--];
            break;
        }
        else if (indexA == -1)
            break;
    }
}
