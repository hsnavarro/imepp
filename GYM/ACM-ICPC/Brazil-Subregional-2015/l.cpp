#include <bits/stdc++.h>
using namespace std;

const int N = 1e4+5;

int n, m, a, A[2*N][55], cnt;

int32_t main(){
  cin >> n >> m;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++) cin >> a, A[i][j] = (a&1 ? 1 : 0);
  }
  cnt = n;
/*
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++) cout << A[i][j] << " ";
    cout << "\n";
  }
  cout << "\n";
*/  
  if(n <= m) return cout << "S\n", 0;
  for(int j=0; j<m; j++) { //collumn to eliminate
    int l = j;
    for(int i=j+1; i<2*n; i++) //find largest pivot
      if(A[i][j]>A[l][j]) l=i;
    
    for(int k = 0; k < m; k++) swap(A[l][k], A[j][k]);

    if(!A[j][j]) {
      //return cout << "S\n", 0;
      for(int k = 0; k < m; k++) swap(A[j][k], A[cnt][k]);
      cnt++;
      continue;
    }
    
    for(int i = j+1; i < 2*n; i++) { //eliminate column
      if(!A[i][j]) continue; 
      for(int k = j; k < m; k++)
        A[i][k] ^= A[j][k];
    }
  }
/*  
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++) cout << A[i][j] << " ";
    cout << "\n";
  }
*/  
  
  int cnt = 0;
  for(int i = 0; i < m; i++) {
    int cond = 0;
    for(int j = 0; j < m; j++) if(A[i][j]) cond = 1;
    cnt += cond;
  }
  cout << (cnt == m ? "N\n" : "S\n");
}
