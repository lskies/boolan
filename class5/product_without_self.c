void replaceWithProducts(int elements[], int n) {
    int a[N] // This is the input
        int products_below[N];
    p=1;
    for(int i=0;i<N;++i) {
          products_below[i]=p;
            p*=a[i];
    }

    int products_above[N];
    p=1;
    for(int i=N-1;i>=0;--i) {
          products_above[i]=p;
            p*=a[i];
    }

    int products[N]; // This is the result
    for(int i=0;i<N;++i)
    {
          products[i]=products_below[i]*products_above[i];
    }
}

void replaceWithProducts(int elements[], int n) {
    int product = 1;
    vector<int> table(n,1);
    for(int  i = 0; i < n; i++){
        table[i] = product;
        product *= elements[i];
    }
  
    product = 1;
    for(i = n-1; i >=0 ; i--){
        elements[i] = table[i] * product;
        product *= elements[i];
    }
}
