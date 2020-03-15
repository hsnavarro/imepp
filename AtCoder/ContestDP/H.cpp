#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1000 + 5, MOD = 1e9 + 7;

int n, m;
ll dp[N][N];
char grid[N][N];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n >> m;
  for(int i = 1; i <= n; i++)
    for(int j = 1; j <= m; j++) cin >> grid[i][j];

  dp[1][1] = 1;
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= m; j++) {
      if(grid[i][j] == '.') {
        ll a = 0, b = 0;
        if(i-1 >= 1) a = dp[i-1][j];
        if(j-1 >= 1) b = dp[i][j-1];
        if(i != 1 or j != 1) dp[i][j] = (a+b)%MOD;
      }
    }
  }
  cout << dp[n][m] << "\n";
}
