bool canCompose(string newspaper, string message) {
    unordered_map<char, int> hashMap;
    int i;
    if (newspaper.length() < message.length()) {
        return false;
    }

    for (i = 0; i < newspaper.length(); i++) {
        hashMap[newspaper[i]]++;
    }

    for (i = 0; i < message.length(); i++) {
        if (hashMap.count(message[i]) == 0) {
            return false;
        }
        if (--hashMap[message[i]] < 0) {
            return false;
        }
    }

    return true;
}

