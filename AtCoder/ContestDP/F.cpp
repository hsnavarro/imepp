#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const int N = 3e3 + 5;

int dp[N][N];
string a, b, ans;

int dpf(int i, int j) {
  if(dp[i][j] != -INF) return dp[i][j];
  if(!i or !j) return dp[i][j] = 0;
  if(a[i-1] == b[j-1]) return dp[i][j] = 1 + dpf(i-1, j-1);
  return dp[i][j] = max(dpf(i-1, j), dpf(i, j-1));
}

void rec(int i, int j) {
  if(!i or !j) return;
  if(a[i-1] == b[j-1]) ans += a[i-1], rec(i-1, j-1);
  else if(dp[i][j] == dp[i-1][j]) rec(i-1, j);
  else rec(i, j-1);
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> a >> b;
  int n = a.size(), m = b.size();
  for(int i = 0; i < N; i++) 
    for(int j = 0; j < N; j++) dp[i][j] = -INF;
  dpf(n, m);
  rec(n, m);
  reverse(ans.begin(), ans.end());
  cout << ans << "\n";
}
