#include <bits/stdc++.h>
using namespace std;

int n, forb[4][4];
string a, b;
vector<string> test;

void generate() {
  for(int i = 1; i <= 3; i++) {
    for(int j = 1; j <= 3; j++) {
      for(int k = 1; k <= 3; k++) {
        if(i != j and j != k and i != k) {
          string aux;
          aux += i + 'a' - 1;
          aux += j + 'a' - 1;
          aux += k + 'a' - 1;
          test.push_back(aux);
        }
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  cin >> a >> b;
  forb[a[0] - 'a' + 1][a[1] - 'a' + 1] = 1;
  forb[b[0] - 'a' + 1][b[1] - 'a' + 1] = 1;

  generate();
  for(auto x : test) {
    int i = x[0] - 'a' + 1;
    int j = x[1] - 'a' + 1;
    int k = x[2] - 'a' + 1;
    if(forb[i][j] or forb[j][k]) continue;
    if(n == 1 or (!forb[1][1] and !forb[2][2] and !forb[3][3])) {
      cout << "YES\n";
      for(int j = 0; j < 3; j++)
        for(int i = 0; i < n; i++) cout << x[j];
      cout << "\n";
      return 0;
    }
    if(n == 1 or !forb[k][i]) {
      cout << "YES\n";
      for(int i = 0; i < n; i++) cout << x;
      cout << "\n";
      return 0;
    } 
  }
  cout << "NO\n";
}
