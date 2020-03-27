#include <bits/stdc++.h>
using namespace std;

const int M = 10;

int n = 4, m = 5;
bitset<(M+1)> A[M], Z;
bitset<M> X;

void add(bitset<(M+1)> &x){
  for(int i = 0; i < n; i++){
    if(!A[i][i] and x[i]) A[i] = x;
    if(A[i][i] and x[i]) x ^= A[i];
  }
}

/*
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
*/

int32_t main(){
  int a;
  for(int i = 0; i < 4; i++){
    for(int j = 0; j < 5; j++) 
      cin >> a, Z[j] = a&1 ? 1 : 0;
      add(Z);
  }
  cout << endl;
  //gauss();
  for(int i = 0; i < 4; i++){
    for(int j = 0; j < 5; j++) cout << A[i][j] << " ";
    cout << endl;
  }

}
