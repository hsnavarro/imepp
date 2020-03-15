#include <bits/stdc++.h>
using namespace std;

const int N = 3e3 + 5;

typedef long double ld;

//dp[toss_number][heads]

int n;
ld dp[N][N], p[N];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  for(int i = 1; i <= n; i++) cin >> p[i];
  dp[1][0] = 1.0 - p[1];
  dp[1][1] = p[1];
  for(int i = 2; i <= n; i++) {
    for(int j = 0; j <= n; j++) {
      dp[i][j] = dp[i-1][j]*(1.0 - p[i]) + 
        (j-1 >= 0 ? dp[i-1][j-1]*p[i] : 0.0);
    }
  }
  ld ans = 0;
  for(int j = 0; j <= n; j++) if(j > n-j) ans += dp[n][j];
  cout << fixed << setprecision(10) << ans << "\n";
}
