#include <bits/stdc++.h>
using namespace std;

const int N = 2000 + 5;

int n, m;
bitset<(N+1)> A[N], aux[N];
bitset<N> X;

void print(){
  for(int i = 0; i < m; i++){
    for(int j = 0; j < m+1; j++) cout << A[i][j] << " ";
    cout << endl;
  }
  cout << endl;
}

void add(bitset<(N+1)> &x){
  for(int i = 0; i < m; i++){
    if(!A[i][i] and x[i]) A[i] = x;
    if(A[i][i] and x[i]) x ^= A[i];
  }
  if(x == (1 << m)) {
    cout << "impossible" << endl;
    exit(0);
  }
}

void gauss() {
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
    aux[i][m - (s[1] - '0')] = 1, neg[i] += isNeg, isNeg = 0;
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

  for(int i = 0; i < n; i++) {
    aux[i][m] = neg[i]&1 ? 0 : 1;
    //for(int j = 0; j <= m; j++) cout << aux[i][j] << " ";
    //cout << endl;
    add(aux[i]);
  }
  //cout << endl;
  //print();
  
  gauss();

  for(int i = m-1; i >= 0; i--) cout << (X[i] ? 'T' : 'F');
  cout << "\n";

}
