#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 100 + 5, W = 1e5 + 5;

int n, w;
ll dp[N][W], wt[N], v[N];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n >> w;
  for(int i = 1; i <= n; i++) cin >> wt[i] >> v[i];

  for(int j = wt[1]; j <= w; j++) dp[1][j] = v[1];
  for(int i = 2; i <= n; i++) {
    for(int j = 1; j <= w; j++) {
      if(j - wt[i] >= 0) dp[i][j] = v[i] + dp[i-1][j - wt[i]];
      dp[i][j] = max(dp[i][j], dp[i-1][j]);
    }
  }
  cout << dp[n][w] << "\n";
}
