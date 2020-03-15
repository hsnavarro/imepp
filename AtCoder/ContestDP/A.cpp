#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n, h[N], dp[N];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  for(int i = 1; i <= n; i++) cin >> h[i];
  memset(dp, 63, sizeof dp);
  dp[1] = 0;
  for(int i = 1; i <= n; i++) {
    if(i+1 <= n) dp[i+1] = min(dp[i+1], dp[i] + abs(h[i+1] - h[i]));
    if(i+2 <= n) dp[i+2] = min(dp[i+2], dp[i] + abs(h[i+2] - h[i]));
  }
  cout << dp[n] << "\n";
} 
