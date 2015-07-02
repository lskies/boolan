vector<string> wordBreak(string s, unordered_set<string> &dict, unordered_map<string,vector<string> >& cache) {
    // memorization
    if(cache.count(s))
        return cache[s];
        
    vector<string> vs;
        
    if(s.empty()) {
        vs.push_back(string());
        return vs;
    }
        
    for(int len = 1; len <= s.size(); ++len ) {
        string prefix = s.substr(0,len);
        if(dict.count(prefix) > 0) {          
            string suffix = s.substr(len);

            // solve subproblem
            vector<string> segments = wordBreak(suffix,dict,cache);          
            for(int i = 0; i < segments.size(); ++i) {
                if(segments[i].empty()) 
                    vs.push_back(prefix);
                else 
                    vs.push_back(prefix + " " + segments[i]);
            }
        }
    }
        
    cache[s] = vs;
    return vs;
}
vector<string> wordBreak(string s, unordered_set<string> &dict) {
        if(s.empty())
                    return vector<string>();
            unordered_map<string,vector<string> > cache;
                return wordBreak(s,dict,cache);
}

