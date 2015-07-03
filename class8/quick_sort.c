int partition( int array[], int left, int right ) {
    int pivot = array[right];
    while( left != right ){
        while( array[left] < pivot && left < right)
            left++;
        if (left < right) {
            swap( array[left], array[right--]);
        }
        while( array[right] > pivot && left < right)
            right--;
        if( left < right )
            swap( array[left++], array[right]);
    }
    //array[left] = pivot;
    return left;
}
void qSort( int array[], int left, int right ){
    if( left >=right )
        return;
    int index = partition( array, left, right);
    qSort(array, left, index - 1);
    qSort(array, index + 1, right);
}

