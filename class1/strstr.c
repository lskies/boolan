bool hasSubstring(const char *str, const char *find) {
    if (str[0] == '\0' && find[0] == '\0')
        return true;

    for(int i = 0; str[i] != '\0'; i++) {
        bool foundNonMatch = false;
        for(int j = 0; find[j] != '\0'; j++) {
            if (str[i + j] != find[j]) {
                foundNonMatch = true;
                break;
            }
        }

        if (!foundNonMatch) {
            return true;
        }
    }

    return false;
}
