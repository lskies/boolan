int minCut(string s) {
    if(s.empty())   return 0;
    vector<vector<bool> > palin(s.size(), vector<bool>(s.size(),false));
    vector<int> minCut(s.size()+1,0);
    for(int i = 0; i <= s.size(); i++)
        minCut[i] = s.size() - i - 1;
       
    for(int i = s.size() - 1; i >= 0; i--) {
        for(int j = i; j < s.size();++j) {              
            if(s[i] == s[j] && ( j - i <= 1 || palin[i+1][j-1] ) ) {
                palin[i][j] = true;
                minCut[i] = min(minCut[j+1]+1, minCut[i]);
            }              
        }
    }
       
    return minCut[0];     
}

