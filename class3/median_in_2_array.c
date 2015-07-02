int find_pivot(int *A,int *B,int n){
    int pa,pb;
    pa=pb=n/2;

    int dist=n/4;

    while(dist>1){

        if(A[pa]==B[pb]){
            return A[pa];
        }

        if(A[pa]<B[pb]){
            pa+=dist;
            pb-=dist;
        }else{
            pa-=dist;
            pb+=dist;
        }

        dist/=2;
    }
    return A[pa];
}
