int climbStairs(int n) {
    if(n <= 1 ) return 1;
    if(n == 2)  return 2;
    
    int p = 1, q = 2, curr;
    for(int i = 3; i <= n; ++i ){
        curr = p + q;
        p = q;
        q = curr;
    }
    return curr;
}
