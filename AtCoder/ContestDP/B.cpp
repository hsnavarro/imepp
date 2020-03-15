#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n, k, dp[N], h[N];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n >> k;
  for(int i = 1; i <= n; i++) cin >> h[i];
  memset(dp, 63, sizeof dp);
  dp[1] = 0;
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= k; j++) {
      if(i+j <= n) dp[i+j] = min(dp[i+j], dp[i] + abs(h[i+j] - h[i]));
    }
  }
  cout << dp[n] << "\n";
}
