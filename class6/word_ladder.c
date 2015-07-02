int ladderLength(string start, string end, unordered_set<string> &dict) {
    int count = 1;    // used to store the answer;
    unordered_set<string> check;    // contains all of the words that is in the path, no duplicate in the path
    queue<string> myque;    // used to level traverse
    myque.push(start);
    myque.push("");    // used to determine which level it is
    string word;
    string mid;    // used to intermediate result
    while(!myque.empty()) {
        word = myque.front();
        myque.pop();
        if(word == end){
            return count;
        }
        if(word.size() == 0 && !myque.empty()) {
            count++;
            myque.push("");
        }
        else if(!myque.empty()) {
            for(int i = 0; i < word.size(); i++) {
                mid = word;
                for(int j = 'a'; j < 'z'; j++){
                    mid[i] = (char)j;
                    if(check.find(mid) == check.end() && dict.find(mid) != dict.end()) {
                        myque.push(mid);
                        check.insert(mid);
                    }
                }
            }
        }
    }
    return 0;
}
