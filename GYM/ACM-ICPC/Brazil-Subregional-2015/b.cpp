#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 2e5 + 5;

int dp[N][2], a[N], n, c;

int32_t main(){
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n >> c;
  for(int i = 1; i <= n; i++) cin >> a[i];
  memset(dp, -63, sizeof dp);
  dp[1][1] = -a[1]-c;
  dp[1][0] = 0;
  for(int i = 2; i <= n; i++){
    dp[i][1] = max(dp[i-1][1], dp[i-1][0] - a[i] - c);
    dp[i][0] = max(dp[i-1][0], dp[i-1][1] + a[i]);
  }
  cout << max(dp[n][0], dp[n][1]) << "\n";
}
