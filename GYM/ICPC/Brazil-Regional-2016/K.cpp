#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define pb push_back

typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef long long ll;

const ll LINF = 0x3f3f3f3f3f3f3f3f;

const int N = 200, INF = 1e9;
struct edge { int v, c, f; };

int n, src, snk, h[N], ptr[N];
vector<edge> edgs;
vector<int> g[N];

int a[N], b[N];

void reset(){
  src = 150;
  snk = 151;
  memset(h, 0, sizeof(h));
  memset(ptr, 0, sizeof(ptr));
  edgs.clear();
  for(int i = 0; i < N; i++) g[i].clear();
}

void add_edge(int u, int v, int c){
  int k = edgs.size();
  edgs.pb({v, c, 0});
  edgs.pb({u, 0, 0});
  g[u].pb(k);
  g[v].pb(k+1);
}

bool bfs(){
  memset(h, 0, sizeof h);
  queue<int> q;
  h[src] = 1;
  q.push(src);
  while(q.size()){
    int u = q.front(); q.pop();
    for(int i : g[u]){
      int v = edgs[i].v;
      if(!h[v] and edgs[i].f < edgs[i].c)
        q.push(v), h[v] = h[u] + 1;
    }
  }
  return h[snk];
}

int dfs(int u, int flow){
  if(!flow or u == snk) return flow;
  for(int &i = ptr[u]; i < g[u].size(); i++){
    edge &dir = edgs[g[u][i]], &rev = edgs[g[u][i]^1];
    int v = dir.v;
    if(h[v] != h[u] + 1) continue;
    int inc = min(flow, dir.c-dir.f);
    inc = dfs(v, inc);
    if(inc){
      dir.f += inc, rev.f -= inc;
      return inc;
    }
  }
  return 0;
}

int dinic(){
  int flow = 0;
  while(bfs()){
    memset(ptr, 0, sizeof ptr);
    while(int inc = dfs(src, INF)) flow += inc;
  }
  return flow;
}

int main(){
  while(~scanf("%d", &n)){
    for(int i = 1; i <= n; i++)
      scanf("%d%d", &a[i], &b[i]);

    int ans = 0;
    for(int i = 1; i <= n; i++){
      reset();
      int num_votos = 0;
      for(int k = 1; k <= n; k++) if(a[k] == i or b[k] == i) num_votos++;
      for(int j = 1; j <= n; j++) if(i != j and a[j] != i and b[j] != i)
        add_edge(src, j, 1);

      for(int j = 1; j <= n; j++) if(i != j){
        if(a[i] == j or b[i] == j) add_edge(j+n, snk, num_votos - 2);
        else add_edge(j+n, snk, num_votos - 1);
      }

      for(int j = 1; j <= n; j++) if(i != j and a[j] != i and b[j] != i){
        add_edge(j, a[j] + n, 1);
        add_edge(j, b[j] + n, 1);
      }

      if(dinic() == n - 1 - num_votos) ans++;
    }
    printf("%d\n", n - ans);
  }
}
