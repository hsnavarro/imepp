#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define pb push_back

const int N = 5000 + 5;
vector<int> adj[N];
vector<pair<int, int>> edgs;
int f[N], par[N], h[N];
int n, qs;

struct query {
  int a, b, g;
};

vector<query> q;

bool cmp(query a, query b) {
  if(a.g == b.g) return a.a == b.a ? a.b < b.b : a.a < b.a;
  return a.g < b.g;
}

void dfs(int x = 1, int p = -1, int hs = 1) {
  if(p != -1) par[x] = p;
  h[x] = hs;
  for(auto v : adj[x]) if(v != p) dfs(v, x, hs+1);
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  int x, y;
  for(int i = 0; i < n-1; i++) {
    cin >> x >> y;
    edgs.pb({x, y});
    adj[x].pb(y);
    adj[y].pb(x);
  }
  dfs();
  cin >> qs;
  int ff;
  for(int i = 0; i < qs; i++) {
    cin >> x >> y >> ff;
    q.push_back({x, y, ff});
  }
  sort(q.begin(), q.end(), cmp);
  for(int i = 0; i < qs; i++) {
    int aux = h[q[i].b] < h[q[i].a] ? q[i].b : q[i].a;
    while(aux != 1) {
      f[aux] = max(f[aux], q[i].g), aux = par[aux];
      if(aux == q[i].a) break;
    }
    if(aux != q[i].a) {
      aux = q[i].a;
      while(aux != 1) f[aux] = max(f[aux], q[i].g), aux = par[aux];
    }
  }
  for(int i = 0; i < N; i++) if(!f[i]) f[i] = (int) 1e6;

  int cond = 1;
  for(int i = 0; i < qs; i++) {
    int mn = (int) 1e6;
    int aux = h[q[i].b] < h[q[i].a] ? q[i].b : q[i].a;
    while(aux != 1) {
      mn = min(mn, f[aux]), aux = par[aux];
      if(aux == q[i].a) break;
    }
    if(aux != q[i].a) {
      aux = q[i].a;
      while(aux != 1) mn = min(mn, f[aux]), aux = par[aux];
    }
    if(mn != q[i].g) { cond = 0; break; }
  }

  if(!cond) cout << -1 << "\n";
  else {
    for(auto e : edgs) cout << (par[e.st] == e.nd ? f[e.st] : f[e.nd]) << " ";
    cout << "\n";
  }
}
