int singleValue(vector<int> array) {
    int value = 0;
    for (int i = 0; i < array.size(); i++) {
        value ^= array[i];
    }
    return value;
}

