#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define pb push_back

typedef pair<int, int> pii;
typedef long long ll;

const int INF = 0x3f3f3f3f;

const int N = 1e5 + 5;

ll n, t[N], a, b, sz[N], sum_t[N], sum_t_tot, res[N];
vector<pair<ll, ll>> adj[N];

void init(int u = 1, int p = -1, ll d = 0) {
  sum_t_tot += t[u];
  sz[u] += 1;
  sum_t[u] += t[u];
  a += d;
  b += t[u]*d;
  for(auto v : adj[u]) {
    if(v.st != p) {
      init(v.st, u, d+v.nd);
      sz[u] += sz[v.st];
      sum_t[u] += sum_t[v.st];
    }
  }
}

void dfs(ll a, ll b, int u = 1, int p = -1) {
  res[u] = t[u]*a+b;
  for(auto x : adj[u]) {
    int v = x.st;
    ll w = x.nd;
    if(v != p)
      dfs(a + (n - 2ll*sz[v]) * w, b + (sum_t_tot - 2ll*sum_t[v]) * w, v, u);
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  for(int i = 1; i <= n; i++) cin >> t[i];
  ll u, v, w;
  for(int i = 0; i < n-1; i++) {
    cin >> u >> v >> w;
    adj[u].pb({v, w});
    adj[v].pb({u, w});
  }
  init(), dfs(a, b);
  for(int i = 1; i <= n; i++) cout << res[i] << "\n";
}
