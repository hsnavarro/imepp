#include <bits/stdc++.h>
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#define st first
#define nd second
#define pb push_back

#ifndef ONLINE_JUDGE
  #define db(x) cerr << #x << " == " << x << endl
  #define dbs(x) cerr << x << endl
  #define _ << ", " <<
#else
  #define db(x) ((void)0)
  #define dbs(x) ((void)0)
#endif

typedef long long ll;
typedef long double ld;

typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;

const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 2500+5, M = 15;

int n, a[N][N];
vector<piii> edgs;
int par[2*N], sz[2*N];

int anc[M][2*N], mx[M][2*N], h[2*N], rt = 1;
vector<pair<int, int>> adj[2*N];

void dfs(int x = rt, int p = -1, int ht = 0){
  anc[0][x] = p, h[x] = ht;
  for(auto v : adj[x]) if(v.st != p) mx[0][v.st] = v.nd, dfs(v.st, x, ht+1);
}

void build(){
  dfs(), anc[0][rt] = rt;
  for(int j = 1; j < M; j++)
    for(int i = 1; i < 2*N; i++) {
      anc[j][i] = anc[j-1][anc[j-1][i]];
      mx[j][i] = max(mx[j-1][i], mx[j-1][anc[j-1][i]]);
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

int find(int x) { return x == par[x] ? x : find(par[x]); }

void merge(int a, int b, int c) {
  int aa = a, bb = b;
  a = find(a), b = find(b);
  if(a == b) return;
  adj[aa].pb({bb, c});
  adj[bb].pb({aa, c});

  if(sz[a] < sz[b]) swap(a, b);
  par[b] = a;
  sz[a] += sz[b];
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  for(int i = 1; i <= n+N; i++) par[i] = i, sz[i] = 1;

  int zeroes = 1;
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= n; j++) {
      cin >> a[i][j];
      if(i == j and a[i][j] != 0) zeroes = 0;
      edgs.pb({a[i][j], {i, j+N}});
      edgs.pb({a[i][j], {j+N, i}});
    }
  }

  sort(edgs.begin(), edgs.end());

  for(auto x : edgs) merge(x.nd.st, x.nd.nd, x.st);
  build();
  int max_ok = 1;
  for(int i = 1; i <= n; i++)
    for(int j = 1; j <= n; j++) {
      //db(i _ j _ lca(i, j+N));
      if(lca(i, j+N) != a[i][j]) max_ok = 0;
    }

  int sim = 1;
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++) if(a[i][j] != a[j][i]) sim = 0;

  int cond = sim & zeroes & max_ok;
  cout << (cond ? "MAGIC\n" : "NOT MAGIC\n");
}

