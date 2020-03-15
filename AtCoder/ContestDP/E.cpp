#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 100 + 5, V = 1e5 + 5;

int n, w;
ll wt[N], v[N], dp[N][V];
// minimum weight to get v of value

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n >> w;
  for(int i = 1; i <= n; i++) cin >> wt[i] >> v[i];
  memset(dp, 63, sizeof dp);
  dp[1][0] = 0;
  dp[1][v[1]] = wt[1];
  for(int i = 2; i <= n; i++) {
    for(int j = 0; j < V; j++) {
      if(j - v[i] >= 0) dp[i][j] = dp[i-1][j-v[i]] + wt[i];
      dp[i][j] = min(dp[i][j], dp[i-1][j]);
    }
  }

  int mx = 0;
  for(int j = 0; j < V; j++) if(dp[n][j] <= w) mx = max(mx, j);
  cout << mx << "\n";
}
