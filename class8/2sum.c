vector<int> addsToTarget(vector<int> &numbers, int target) {
    unordered_map<int, int> numToIndex;
    vector<int> vi(2);
    for (auto it = numbers.begin(); it != numbers.end(); it++) {
        if (numToIndex.count(target - *it)) {
            vi[0] = numToIndex[target - *it] + 1;
            vi[1] = (int)(it - numbers.begin()) + 1;
            return vi;
        }
        numToIndex[*it] = (int)(it - numbers.begin());
    }
}
