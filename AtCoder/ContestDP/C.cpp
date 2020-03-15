#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
const int INF = 0x3f3f3f3f;

int n, dp[N][3], pts[N][3];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  for(int i = 1; i <= n; i++) 
    cin >> pts[i][0] >> pts[i][1] >> pts[i][2];
  
  dp[1][0] = pts[1][0];
  dp[1][1] = pts[1][1];
  dp[1][2] = pts[1][2];
  for(int i = 2; i <= n; i++) {
    dp[i][0] = pts[i][0] + 
      max({dp[i-1][1], dp[i-1][2], (i-2 >= 0 ? dp[i-2][0] : 0)});
    dp[i][1] = pts[i][1] + 
      max({dp[i-1][0], dp[i-1][2], (i-2 >= 0 ? dp[i-2][1] : 0)});
    dp[i][2] = pts[i][2] + 
      max({dp[i-1][0], dp[i-1][1], (i-2 >= 0 ? dp[i-2][2] : 0)});
  }
  cout << max({dp[n][0], dp[n][1], dp[n][2]}) << "\n";
}
