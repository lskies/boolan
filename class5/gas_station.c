int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
    int size = gas.size();
    int subSum = 0, sum = 0;
    int array[gas.size()];
    int index = 0;
    for(int i = 0; i < size; i++){
        array[i] = gas[i] - cost[i];
        sum += array[i];
    }
    if (sum < 0) 
        return -1;
    for(int i = 0; i < size; i++) {
        subSum += array[i];
        if(subSum < 0) {
            subSum = 0;
            index = i + 1;
        }
    }
    return index;
}

