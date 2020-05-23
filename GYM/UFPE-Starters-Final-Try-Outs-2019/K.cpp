#include <bits/stdc++.h>
using namespace std;

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

#define int long long

typedef long long ll;
typedef long double ld;

typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;

const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e5+5, M = 5e6 + 5;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

int n, m, o, d;
vector<pair<int, ll>> adj[N], adjt[N];
vector<pair<pair<int, int>, pair<ll, ll>>> edgs;
int u, v, a, p;

int cmp[M];

void sieve() {
  for(ll i = 2; i < M; i++) {
    if(!cmp[i]) {
      for(ll j = i*i; j < M; j += i) cmp[j] = 1;
    }
  }
}

int find(int x) {
  while(cmp[x]) x--;
  return x;
}

int cost, vis[N];
priority_queue<pair<int, pair<int, int>>> pq;

int prim(int s = o) {
  pq.push({LINF, {s, LINF}});
  int keep_mn = INF;
  while(pq.size()) {
    int ud = pq.top().st;
    int u = pq.top().nd.st;
    int mn = pq.top().nd.nd;
    pq.pop();
    if(vis[u]) continue;
    if(u == d) keep_mn = min(keep_mn, mn);
    vis[u] = 1;
    for(auto x : adjt[u]) {
      int v = x.st;
      int w = x.nd;
      if(!vis[v]) pq.push({w, {v, min(w, mn)}});
    }
  }
  return keep_mn;
}

int dist[N];
priority_queue<pii> pq2;
void dijkstra(int s = o) {
  memset(dist, 63, sizeof dist);
  dist[s] = 0;
  pq2.push({0, s});
  while(pq2.size()) {
    int ud = -pq2.top().st;
    int u = pq2.top().nd;
    pq2.pop();
    if(dist[u] < ud) continue;
    for(auto x : adj[u]) {
      int v = x.st;
      int w = x.nd;
      if(dist[u] + w < dist[v]) {
        dist[v] = dist[u] + w;
        pq2.push({-dist[v], v});
      }
    }
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  sieve();
  cin >> n >> m >> o >> d;
  for(int i = 0; i < m; i++) {
    cin >> u >> v >> a >> p;
    a = find(a);
    edgs.pb({{u, v}, {a, p}});
    adjt[u].pb({v, a});
  }
  int val =  prim();

  for(auto x : edgs) {
    int uu = x.st.st;
    int vv = x.st.nd;
    int aa = x.nd.st;
    int pp = x.nd.nd;
    if(aa >= val) {
      adj[uu].pb({vv, pp});
    }
  }
  dijkstra();
  if(dist[d] == LINF) cout << 0 << " " << 0 << "\n";
  else cout << val << " " << val*dist[d] << "\n";
}

