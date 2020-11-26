#include <bits/stdc++.h>
using namespace std;

const int N = 50*50 + 10;
const int INF = 0x3f3f3f3f;

struct edge { int v, c, f; };

int n, m, s = N-1, t = N-2, A, B, h[N], st[N];
vector<edge> edgs;
vector<int> g[N];

int lin(int x, int y) {
  return x*m + y;
}

// directed from u to v with cap(u, v) = c
void add_edge(int u, int v, int c) {
  int k = edgs.size();
  edgs.push_back({v, c, 0});
  edgs.push_back({u, 0, 0});
  g[u].push_back(k);
  g[v].push_back(k+1);
}

int bfs() {
  memset(h, 0, sizeof h);
  h[s] = 1;
  queue<int> q;
  q.push(s);
  while(q.size()) {
    int u = q.front(); q.pop();
    for(auto i : g[u]) {
      int v = edgs[i].v;
      if(!h[v] and edgs[i].f < edgs[i].c)
        h[v] = h[u] + 1, q.push(v);
    }
  }
  return h[t];
}

int dfs(int u, int flow) {
  if(!flow or u == t) return flow;
  for(int &i = st[u]; i < g[u].size(); i++) {
    edge &dir = edgs[g[u][i]], &rev = edgs[g[u][i]^1];
    int v = dir.v;
    if(h[v] != h[u] + 1) continue;
    int inc = min(flow, dir.c - dir.f);
    inc = dfs(v, inc);
    if(inc) {
      dir.f += inc, rev.f -= inc;
      return inc;
    }
  }
  return 0;
}

int dinic() {
  int flow = 0;
  while(bfs()) {
    memset(st, 0, sizeof st);
    while(int inc = dfs(s, INF)) flow += inc;
  }
  return flow;
}

char c;
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n >> m >> A >> B;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      cin >> c;

      if(c == '.') add_edge(s, lin(i, j), B);
      else add_edge(lin(i, j), t, B);

      for(int k = 0; k < 4; k++) {
        int ni = i + dx[k];
        int nj = j + dy[k];

        if(ni < 0 or ni == n or nj < 0 or nj == m) continue;

        add_edge(lin(i, j), lin(ni, nj), A);
      }

    }
  }

  cout << dinic() << "\n";
}
