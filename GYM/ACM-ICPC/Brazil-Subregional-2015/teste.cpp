// Gaussian Elimination
// O(n*m^2)

// if n < m, there's no solution

// check if there's a null line with a
// not null answer to see if it's a impossible system

// X holds the solution

int n, m;
bitset<(M+1)> A[N];
bitset<M> X;

void add(){
  for(int i = 0; i < n; i++){
    if(!A[i][i] and A[n][i]) A[i] = A[n];
    if(A[i][i] and A[n][i]) A[n] ^= A[i];
  }
}

void gauss(){
  for(int j=0; j<m; j++) {
    int l = j;
    for(int i=j+1; i<n; i++) if(A[i][j]>A[l][j]) l=i;
    if(!A[l][j]) l = n;
    swap(A[l], A[j]);
    if(!A[j][j]) add();
    else {
      for(int i = j+1; i < n; i++)
        if(A[i][j]) A[i] ^= A[j];
    }
  }

  for(int i = m-1; i >= 0; i--){
    for(int j = m-1; j > i; j--) if(A[i][j]) A[i][m] = A[i][m]^X[j];
    X[i] = A[i][m];
  }
}
