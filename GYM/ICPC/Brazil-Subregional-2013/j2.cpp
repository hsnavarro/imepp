#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second

typedef pair<int, int> pii;
typedef pair<int, pii> piii;

const int N = 2e4 + 5;
const int M = 20;
const int INF = 0x3f3f3f3f;

int n, m, s, a, b, w, par[N], sz[N], h[N], anc[N][M], mn[N][M];
vector<piii> edge;
vector<pii> adj[N];

int find(int a) { return par[a] == a ? a : par[a] = find(par[a]); }

void unite(int a, int b, int peso){
  a = find(a), b = find(b);
  if(a == b) return;
  adj[a].push_back({b, peso});
  adj[b].push_back({a, peso});
  if(sz[a] < sz[b]) swap(a, b);
  sz[a] += sz[b], par[b] = a;
}

void dfs(int x, int p = -1){
  if(p != -1) anc[x][0] = p, h[x] = h[p] + 1;
  for(auto v : adj[x]) if(v.st != p) dfs(v.st, x), mn[v.st][0] = v.nd;
}

void build(){
  for(int j = 1; j < M-1; j++){
    for(int i = 1; i <= n; i++){
      anc[i][j] = anc[anc[i][j-1]][j-1];
      mn[i][j] = min(mn[i][j-1], mn[anc[i][j-1]][j-1]);
    }
  }
}

void reset(int n){
  memset(h, sizeof h, 0);
  memset(anc, sizeof anc, 0);
  for(int i = 1; i <= n; i++) adj[i].clear();
  edge.clear();
}

int mini(int a, int b){
  if(h[a] < h[b]) swap(a, b);
  int mna = INF, mnb = INF;
  for(int i = M-1; i >= 0; i--){
    if(h[a] - (1 << i) >= h[b]) mna = min(mna, mn[a][i]), a = anc[a][i];
  }
  if(a == b) return min(mna, mnb);

  for(int i = M-1; i >= 0; i--){
    if(anc[a][i] != anc[b][i]){
      mna = min(mna, mn[a][i]);
      mnb = min(mnb, mn[b][i]);
      a = anc[a][i];
      b = anc[b][i];
    }
  }
  mna = min(mna, mn[a][0]);
  mnb = min(mnb, mn[b][0]);
  return min(mna, mnb);
}


int32_t main(){
  ios_base::sync_with_stdio(0), cin.tie(0);
  while(cin >> n >> m >> s){
    for(int i = 1; i <= n; i++) sz[i] = 1, par[i] = i;
    for(int i = 0; i < m; i++){
      cin >> a >> b >> w;
      edge.push_back({-w, {a, b}});
    }
    sort(edge.begin(), edge.end());
    for(auto x  : edge) unite(x.nd.st, x.nd.nd, -x.st);
    memset(mn, 63, sizeof mn);
    anc[1][0] = 1, dfs(1);
    build();
    while(s--){
      cin >> a >> b;
      cout << mini(a, b) << "\n";
    }
    reset(n);
  }
}
