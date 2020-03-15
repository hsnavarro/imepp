#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define pb push_back

const int INF = 0x3f3f3f3f;
const int N = 30 + 5;

struct edge { int vx, vy, c, f; };

int n, m, col, sx = 0, sy = 0, tx = 2*N-2, ty = 2*N-2, h[2*N][2*N], st[2*N][2*N];
int cost[N];
vector<edge> edgs;
vector<int> g[2*N][2*N];
char grid[N][N];

// directed from u to v with cap(u, v) = c
void add_edge(int ux, int uy, int vx, int vy, int c) {
  int k = edgs.size();
  edgs.pb({vx, vy, c, 0});
  edgs.pb({ux, uy, 0, 0});
  g[ux][uy].pb(k);
  g[vx][vy].pb(k+1);
}

int bfs() {
  memset(h, 0, sizeof h);
  h[sx][sy] = 1;
  queue<pair<int, int>> q;
  q.push({sx, sy});
  while(q.size()) {
    int ux = q.front().st; 
    int uy = q.front().nd;
    q.pop();
    for(auto i : g[ux][uy]) {
      int vx = edgs[i].vx;
      int vy = edgs[i].vy;
      if(!h[vx][vy] and edgs[i].f < edgs[i].c)
        h[vx][vy] = h[ux][uy] + 1, q.push({vx, vy});
    }
  }
  return h[tx][ty];
}

int dfs(int ux, int uy, int flow) {
  if(!flow or (ux == tx and uy == ty)) return flow;
  for(int &i = st[ux][uy]; i < g[ux][uy].size(); i++) {
    edge &dir = edgs[g[ux][uy][i]], &rev = edgs[g[ux][uy][i]^1];
    int vx = dir.vx;
    int vy = dir.vy;
    if(h[vx][vy] != h[ux][uy] + 1) continue;
    int inc = min(flow, dir.c - dir.f);
    inc = dfs(vx, vy, inc);
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
    while(int inc = dfs(sx, sy, INF)) flow += inc;
  }
  return flow;
}

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n >> m >> col;
  swap(n, m);
  int startx, starty;
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= m; j++) {
      cin >> grid[i][j];
      if(grid[i][j] == 'B') startx = i, starty = j;
    }
  }
  for(int i = 0; i < col; i++) cin >> cost[i];

  // add edge from source to start
  add_edge(sx, sy, startx, starty, INF);

  // add edge from borders to sink
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= m; j++) {
      if(i != 1 and i != n and j != 1 and j != m) continue;
      add_edge(i+N, j+N, tx, ty, INF);
    }
  }

  // add edge from in to out
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= m; j++) {
      if(grid[i][j] == '.' or grid[i][j] == 'B') add_edge(i, j, i+N, j+N, INF);
      else add_edge(i, j, i+N, j+N, cost[grid[i][j] - 'a']);
    }
  }

  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= m; j++) {
      for(int k = 0; k < 4; k++) {
        int nx = i + dx[k];
        int ny = j + dy[k];
        if(nx < 1 or nx > n or ny < 0 or ny > m) continue;
        add_edge(i+N, j+N, nx, ny, INF);
      }
    }
  }

  int ans = dinic();
  cout << (ans == INF ? -1 : ans)  << "\n";
}
