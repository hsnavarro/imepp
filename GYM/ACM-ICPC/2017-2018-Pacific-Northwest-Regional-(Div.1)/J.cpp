#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define pb push_back

typedef long long ll;

const int N = 30 + 5;

int n, m;
char grid[N][N];
int mn[N], mx[N];

ll dp[N][N];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n >> m;
  for(int i = 1; i <= n; i++) {
    mn[i] = m+1;
    for(int j = 1; j <= m; j++) {
      cin >> grid[i][j];
      if(grid[i][j] == 'R') mn[i] = min(mn[i], j);
      if(grid[i][j] == 'B') mx[i] = max(mx[i], j);
    }
  }

  for(int i = 1; i <= n; i++) {
    for(int k = mx[i]; k < mn[i]; k++) {
      if(i == 1) dp[i][k] = 1;
      else {
        for(int j = k; j <= m; j++)
          dp[i][k] += dp[i-1][j];
      }
    }
  }
  ll ans = 0;
  for(int k = 0; k <= m; k++) ans += dp[n][k];
  cout << ans << "\n";
}
