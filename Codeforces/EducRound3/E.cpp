#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define pb push_back

typedef pair<int, int> pii;
typedef pair<int, pii> piii;


typedef long long ll;

const int N = 2e5 + 5, M = 25;

int n;
vector<pii> adj[N];

int m, par[N], sz[N];
int a, b, w;

int anc[M][N], mx[M][N], h[N], rt = 1;

void dfs(int x = rt, int p = -1, int ht = 0){
  anc[0][x] = p, h[x] = ht;
  for(auto v : adj[x]) if(v.st != p) mx[0][v.st] = v.nd, dfs(v.st, x, ht+1);
}

void build(){
  dfs(), anc[0][rt] = rt;

  for(int j = 1; j < M; j++) {
    for(int i = 1; i <= n; i++) {
      anc[j][i] = anc[j-1][anc[j-1][i]];
      mx[j][i] = max(mx[j-1][i], mx[j-1][anc[j-1][i]]);
    }
  }
}

int lca(int u, int v){
  if(h[u] < h[v]) swap(u, v);
  int mx1 = 0, mx2 = 0;
  for(int i = M-1; i >= 0; i--) if(h[u] - (1<<i) >= h[v]) {
    mx1 = max(mx1, mx[i][u]);
    u = anc[i][u];
  }
  
  if(u == v) return max(mx1, mx2);
  for(int i = M-1; i >= 0; i--) if(anc[i][u] != anc[i][v]) {
    mx1 = max(mx1, mx[i][u]);
    mx2 = max(mx2, mx[i][v]);
    u = anc[i][u], v = anc[i][v];
  }
  mx1 = max(mx1, mx[0][u]);
  mx2 = max(mx2, mx[0][v]);
  return max(mx1, mx2);
}

int find(int a) { return a == par[a] ? a : par[a] = find(par[a]); }

vector<piii> edgs, edges;

void unite(int a, int b){
    if(find(a) == find(b)) return;
    a = find(a), b = find(b);
    if(sz[a] < sz[b]) swap(a, b);
    sz[a] += sz[b], par[b] = a;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n >> m;
  for(int i = 1; i <= n; i++) par[i] = i, sz[i] = 1;
  for(int i = 0; i < m; i++) {
    cin >> a >> b >> w;
    edgs.push_back({w, {a, b}});
    edges.push_back({w, {a, b}});
  }

  sort(edges.begin(), edges.end());
  ll cost = 0;
  for(auto e : edges) { 
    if(find(e.nd.st) != find(e.nd.nd)) {
      cost += e.st, unite(e.nd.st, e.nd.nd);
      int x = min(e.nd.st, e.nd.nd);
      int y = max(e.nd.st, e.nd.nd);
      adj[x].pb({y, e.st});
      adj[y].pb({x, e.st});
    }
  }

  build();
  
  for(auto &x : edgs) {
    int aa = x.nd.st, bb = x.nd.nd;
    cout << 1ll*cost + 1ll*x.st - 1ll*lca(aa, bb) << "\n";
  }

}
