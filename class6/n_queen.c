bool checkValid( int row1, int col1,int *rowCol ) {  
    for( int row2 = row1 - 1; row2 >= 0; row2--) {
        if( rowCol[row2] == col1 )
            return false;
        if( abs(row1 - row2) == abs( rowCol[row2] - col1 ) )
            return false;
    }
    return true;
}

void placeQ( int row, int rowCol[], vector<int*>& res ) {
    if (row == GRID_SIZE) {
        //winning
        int p[GRID_SIZE];
        for( int i =0; i < GRID_SIZE; i++)
            p[i] = rowCol[i];
        res.push_back(p);
        return;
    }

    int col = 0;
    for(col = 0; col < GRID_SIZE; col++) {
        if( checkValid(row, col, rowCol) ) {
            rowCol[row] = col;
            placeQ( row+1, rowCol, res);
            // because we rewrite rowCol[row] everytime, 
 // so backtracking is inferred here
        }     
    } 
}

