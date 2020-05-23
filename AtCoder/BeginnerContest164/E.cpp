#include <bits/stdc++.h>
using namespace std;

mt19937_64 llrand((int) chrono::steady_clock::now().time_since_epoch().count());

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
const int N = 50+5;

struct edge {
  int to, cost, dur;
};

int n, m, s, ans[N], c[N], d[N];
vector<edge> adj[N];
map<pair<int, int>, int> dist;

void dijkstra(int st) {
  memset(ans, 63, sizeof dist);
  dist[{st, s}] = 0;
  priority_queue<pair<int, pair<int, int>>> pq;
  pq.push({0, {st, s}});
  while(pq.size()) {
    int ud = -pq.top().st;
    int u = pq.top().nd.st;
    ans[u] = min(ans[u], ud);
    int amt = pq.top().nd.nd;
    pq.pop();

    if(ud > dist[{u, amt}]) continue;
    
    for(auto v : adj[u]) {
      int k = (v.cost - amt + c[u] - 1) / c[u];
      int tot = k * d[u] + v.dur;
      int newamt = amt + c[u] * k;
      if(!dist.count({v.to, newamt}) or dist[{v.to, newamt}] > dist[{u, amt}] + tot) {
        dist[{v.to, newamt}] = dist[{u, amt}] + tot;
        pq.push({-dist[{v.to, newamt}], {v.to, newamt}});
      }
    }
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n >> m >> s;
  int u, v, a, b;
  while(m--) {
    cin >> u >> v >> a >> b;
    adj[u].pb({v, a, b});
    adj[v].pb({u, a, b});
  }

  for(int i = 1; i <= n; i++) cin >> c[i] >> d[i];
  dijkstra(1);
  for(int i = 2; i <= n; i++) cout << ans[i] << "\n";
}
