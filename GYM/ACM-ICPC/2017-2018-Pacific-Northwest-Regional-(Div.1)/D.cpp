#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define pb push_back

typedef long long ll;

const int N = 5e4 + 5;

int n, cmp[N];
vector<pair<int, int>> adj[N];
vector<int> ans;

void dfs(int u, int p, int c) {
  for(auto x : adj[u]) {
    int v = x.nd;
    int cv = x.st;
    if(v != p and cv == c) cmp[1]++, cmp[u]--, cmp[v]++;
  }

  for(int i = 0; i+1 < adj[u].size(); i++) {
    if(adj[u][i].nd == p) continue;
    if(adj[u][i].st == adj[u][i+1].st)
      cmp[adj[u][i].nd]++, cmp[adj[u][i+1].nd]++;
  }

  for(auto x : adj[u]) {
    if(x.nd == p) continue;
    dfs(x.nd, u, x.st);
  }
}

void propag(int u, int p) {
  if(!cmp[u]) ans.pb(u);
  for(auto x : adj[u]) {
    if(x.nd == p) continue;
    cmp[x.nd] += cmp[u];
    propag(x.nd, u);
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  int a, b, c;
  for(int i = 0; i < n-1; i++) {
    cin >> a >> b >> c;
    adj[a].pb({c, b});
    adj[b].pb({c, a});
  }
  for(int i = 1; i <= n; i++) sort(adj[i].begin(), adj[i].end());
  dfs(1, -1, -1);
  propag(1, -1);
  cout << ans.size() << "\n";
  sort(ans.begin(), ans.end());
  for(auto x : ans) cout << x << "\n";

}
