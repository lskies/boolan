void searchRangeHelper(int array[], int left, int right, int target, int &begin, int &end) {
    if (left > right) {
        return;
    }

    int mid = right - (right - left) / 2;
    if (array[mid] == target) {
        if (mid < begin || begin == -1) {
            begin = mid;
        }
        if (mid > end) {
            end = mid;
        }
        searchRangeHelper(array, left, mid - 1, target, begin, end);
        searchRangeHelper(array, mid + 1, right, target, begin, end);
    }
    else if (array[mid] < target) {
        searchRangeHelper(array, mid + 1, right, target, begin, end);
    }
    else {
        searchRangeHelper(array, left, mid - 1, target, begin, end);
    }
}

vector<int> searchRange(int A[], int n, int target) {
    int begin = -1, end = -1;

    searchRangeHelper(A, 0, n - 1, target, begin, end);

    vector<int> ans;
    ans.push_back(begin);
    ans.push_back(end);
    return ans;
}

