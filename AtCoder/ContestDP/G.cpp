#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n, m, dp[N], in[N];
vector<int> adj[N];

void dfs(int u, int p) {
  for(auto v : adj[u]) {
    if(v == p) continue;
    if(!dp[v]) dfs(v, u);
    dp[u] = max(dp[u], dp[v]+1);
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n >> m;
  int a, b;
  for(int i = 0; i < m; i++) {
    cin >> a >> b;
    adj[a].push_back(b), in[b]++;
  }

  for(int i = 1; i <= n; i++) if(!in[i]) dfs(i, -1);
  int mx = 0;
  for(int i = 1; i <= n; i++) mx = max(mx, dp[i]);
  cout << mx << "\n";
}
