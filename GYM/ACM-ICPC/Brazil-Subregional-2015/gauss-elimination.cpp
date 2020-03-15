// Gaussian Elimination
// O(n*m^2)

// if n < m, there's no solution

// check if there's a null line with a 
// not null answer to see if it's a impossible system

// X holds the solution

int n, m;
vector<vector<int>> A(N, vector<int>(M+1));
vector<int> X(M);

void add(){
  for(int i = 0; i < n; i++){
    if(!A[i][i] and A[n][i]) A[i] = A[n];
    if(A[i][i] and A[n][i])
      for(int j = 0; j < m+1; j++) 
        A[n][j] ^= A[i][j];
  }
}

void gauss(){
  for(int j=0; j<m; j++) {
    int l = j;
    for(int i=j+1; i<n; i++) if(A[i][j]>A[l][j]) l=i;
    if(!A[l][j]) l = n;
    for(int k = 0; k < m+1; k++) swap(A[l][k], A[j][k]);
    if(!A[j][j]) add();
    else {
      for(int i = j+1; i < n; i++)
        if(A[i][j]) 
          for(int k = j; k < m+1; k++) A[i][k] ^= A[j][k];
    }
  }

  for(int i = m-1; i >= 0; i--){
    for(int j = m-1; j > i; j--) if(A[i][j]) A[i][m] ^= X[j];
    X[i] = A[i][m];
  }
}
