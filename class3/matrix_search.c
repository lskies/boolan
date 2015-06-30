bool isElementInMatrix(int **matrix, int M, int N, int target) {
    int row = 0;
    int column = N - 1;

    while (row < M && column >= 0) {
        if (matrix[row][column] == target) {
            return true;
        } else if (matrix[row][column] < target) {
            row++;
        } else {
            column--;
        }
    }
    return false;
}

