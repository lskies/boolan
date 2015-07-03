int lcs( string str1, string str2) {
    vector<vector<int>> length( str1.size()+1, vector<int>(str2.size()+1);
    for(int i = 0; i < str1.size(); i++) {
        for(int j = 0; j < str2.size(); j++) {
            if(i == 0 || j == 0)
                length[i][j] = 0;
            else if (str1[i-1] == str2[j-1])
                length[i][j] = length[i-1][j-1] + 1;
            else 
                length[i][j] = max(length[i-1][j], length[i][j-1]);
        }
    }
    return length[str1.size()][str2.size()];
}


