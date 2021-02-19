#include <bits/stdc++.h>
using namespace std;

const int N = 100 + 5;

int dp[N][N][N];
tuple<int, int, int> prox[N][N][N];

int nxt[N][26];

string s1, s2, virus;

void prekmp(string &p) {
  nxt[0][p[0] - 'a'] = 1;
  for(int i = 1, j = 0; i <= p.size(); i++) {
    for(int c = 0; c < 26; c++) nxt[i][c] = nxt[j][c];
    if(i == p.size()) continue;
    nxt[i][p[i] - 'a'] = i+1;
    j = nxt[j][p[i] - 'a'];
  }
}

int main() {
  cin >> s1 >> s2 >> virus;

  int n = (int) s1.length();
  int m = (int) s2.length();
  int v = (int) virus.length();

  prekmp(virus);

  for(int i = 0; i <= n; i++) {
    for(int j = 0; j <= m; j++) {
      for(int k = 0; k < v; k++) {
        
        auto &curValue = dp[i][j][k];

        auto &passFirst = dp[i+1][j][k];
        auto &passSecond = dp[i][j+1][k];

        if(i != n and passFirst < curValue) { 
          passFirst = curValue;
          prox[i][j][k] = { i + 1, j, k };
        }

        if(j != m and passSecond < curValue) {
          passSecond = curValue;
          prox[i][j][k] = { i, j + 1, k };
        }

        if(i != n and j != m and s1[i] == s2[j]) {
          
          char ch = s1[i] - 'a';
          int nextPos = nxt[k][ch];
          
          if(nextPos != v) {
            auto &match = dp[i+1][j+1][nextPos];

            if(match < curValue) {
              match = curValue;
              prox[i][j][k] = { i + 1, j + 1, nextPos };
            }
            
          }
        }

      }
    } 
  }

  int mx = 0;
  for(int k = 0; k < v; k++) mx = max(mx, dp[n][m][k]);

  if(mx != 0) {

    tuple<int, int, int> start = {0, 0, 0};

    string ans;

    while(get<0>(start) != n or get<1>(start) != m) {

      auto [ i, j, k ] = start;

      auto nextSt = prox[i][j][k];

      auto [ ni, nj, _ ] = nextSt;

      if(ni == i + 1 and nj == j + 1) ans += s1[i];

      start = nextSt;
      
      cout << "ni, nj " << ni << " " << nj << endl;
    }

    cout << ans << "\n";

  } else {
    cout << mx << "\n";
  }

}