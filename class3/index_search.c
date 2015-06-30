int indexSearch(int *array, int left, int right) {
    if (left > right) {
        // value not found
        return -1;
    }

    int mid = right - (right - left) / 2;    
    if (array[mid] == mid) {
        return mid;
    } else if (array[mid] < mid) {
        return indexSearch(array, mid + 1, right);
    } else {
        return indexSearch(array, left, mid - 1);
    }
}
