#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5, M = N*N;
const int INF = 0x3f3f3f3f;

int dp[M];

int n, k;
vector<int> a;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n >> k;
  a.resize(n);
  for(int i = 0; i < n; i++) cin >> a[i];
  sort(a.begin(), a.end());
  a.resize(unique(a.begin(), a.end()) - a.begin());

  int mn = a[0];
  for(int i = 0; i < n; i++) a[i] -= mn;

  memset(dp, 63, sizeof dp);
  dp[0] = 0;
  for(int k = 0; k < M; k++) {
    if(dp[k] == INF) continue;
    for(int i = 0; i < n; i++) {
      if(a[i] + k >= M) continue;
      dp[a[i] + k] = min(dp[a[i] + k], dp[k] + 1);
    }
  }

  for(int i = 0; i < M; i++) if(dp[i] <= k) cout << i + k*mn << " ";
  cout << "\n";
}
