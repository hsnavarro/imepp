#include <bits/stdc++.h>
using namespace std;

const int N = 1e4+5;

int n, m, a, cnt;
vector<vector<int>> A(N+1, vector<int>(55));

void add(vector<int> &x){
  for(int i = 0; i < n; i++){
    if(!x[i]) continue;
    if(!A[i][i] and x[i]) A[i] = x;
    if(A[i][i] and x[i]) {
      for(int j = 0; j < m; j++)
      x[j] ^= A[i][j];
    }
  }
}

int32_t main(){
  cin >> n >> m;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++) cin >> a, A[i][j] = (a&1 ? 1 : 0);
  }
  if(n <= m) return cout << "S\n", 0;

  for(int j=0, l = j; j<m; j++) {
    for(int i=j+1; i<n; i++)
      if(A[i][j]>A[l][j]) l=i;
    
    for(int k = 0; k < m; k++) swap(A[l][k], A[j][k]);

    if(!A[j][j]) {
      for(int k = 0; k < m; k++) swap(A[j][k], A[n][k]);
      add(A[n]);
    } else {
      for(int i = j+1; i < n; i++) 
        if(A[i][j]) 
          for(int k = j; k < m; k++) A[i][k] ^= A[j][k];
    }
  }

  int cnt = 0;
  for(int i = 0; i < m; i++) {
    int cond = 0;
    for(int j = 0; j < m; j++) if(A[i][j]) cond = 1;
    cnt += cond;
  }
  cout << (cnt == m ? "N\n" : "S\n");
}
