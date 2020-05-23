#include <bits/stdc++.h>
using namespace std;

const int N = 50 + 5;

int n, dp[N][2], a[N];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  for(int i = 0; i < n; i++) cin >> a[i];

  for(int i = 0; i < n; i++) {
    dp[i][0] = dp[i][1] = 1;
    for(int j = 0; j < i; j++) {
      if(a[j] < a[i]) dp[i][0] = max(dp[i][0], dp[j][1] + 1);
      if(a[j] > a[i]) dp[i][1] = max(dp[i][1], dp[j][0] + 1);
    } 
  }

  int mx = 0;
  for(int i = 0; i < n; i++) mx = max({mx, dp[i][0], dp[i][1]});
  cout << mx << "\n";
}
