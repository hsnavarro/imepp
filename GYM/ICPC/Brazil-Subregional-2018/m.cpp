#include <bits/stdc++.h>
using namespace std;
 
const int N = 2000 + 5;
 
int n, m;
bitset<(N+1)> A[N];
bitset<N> X;
 
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
    X[i] = A[i][i] ? A[i][m] : 1;
  }
}
 
int neg[N], isNeg;
string line, s;
 
void go(int i, string& s){
  if(s == "not") isNeg = 1;
  if(s[0] == 'x') {
    A[i][m - (s[1] - '0')] = 1, neg[i] += isNeg, isNeg = 0;
  }
  s.clear();
}
 
int main(){
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n >> m;
  cin.ignore();
  for(int i = 0; i < n; i++) {
    getline(cin, line);
    isNeg = 0;
    for(int j = 0; j < line.size(); j++){
      if(line[j] == ' ' or line[j] == ')') {
        go(i, s);
        if(line[j] == ')') break;
      }
      else if(line[j] != '(') s += line[j];
    }
  }
 
  for(int i = 0; i < n; i++) A[i][m] = neg[i]&1 ? 0 : 1;
 
  /*
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m+1; j++) cout << A[i][j] << " ";
    cout << endl;
  }
  */
 
  gauss();
 
  // check if it's impossible
  for(int i = 0; i < n; i++) 
    if(A[i] == (1 << m)) return cout << "impossible\n", 0;
  
  for(int i = m-1; i >= 0; i--) cout << (X[i] ? 'T' : 'F');
  cout << "\n";
 
}
