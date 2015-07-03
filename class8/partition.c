void partition(int v[], int n, int key) {
    int i = 0;
    int j = n - 1;
    while (j > i) {
        if (v[i] >= key) {
            swap(v[i], v[j]);
            --j;
        }
        else
            ++i;

        if (v[j] < key) {
            swap(v[i],v[j]);
            ++i;
        }
        else
            --j;
    }
}
