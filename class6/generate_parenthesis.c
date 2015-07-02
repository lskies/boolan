void parenthesesCombination(int leftRem, int rightRem, string &path, vector<string> &paths ){
    if(leftRem < 0 || rightRem < 0)
        return;
        
    if(leftRem > 0) {
        // make choice        
        path.push_back('(');
        parenthesesCombination(leftRem-1,rightRem,path,paths); 

        // backtracking       
        path.pop_back();
  }
        
    if(leftRem < rightRem) { 
        // make choice
        path.push_back(')'); 
        rightRem -= 1;
        if(rightRem == 0)
            paths.push_back(path);    // winning
        parenthesesCombination (leftRem, rightRem, path, paths); 

        // backtracking        
        path.pop_back();          
    }       
}

vector<string> generateParenthesis(int n) {        
    vector<string> res;
    if(n <= 0)  
        return res;      
    string path;
    parenthesesCombination(n, n, path, res);
        
    return res;
}

