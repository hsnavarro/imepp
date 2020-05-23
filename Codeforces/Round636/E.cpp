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

typedef long long ll;
typedef long double ld;

typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;

const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int N = 2e5+5;

int t, n, m, a, b, c;
int p[N], dista[N], distb[N], distc[N];
ll ps[N];
vector<int> adj[N];

void bfs(int s, int *dist) {
  dist[s] = 0;
  queue<int> q;
  q.push(s);
  while(q.size()) {
    int u = q.front();
    q.pop();
    
    for(auto v : adj[u])  
      if(dist[v] == INF) dist[v] = dist[u] + 1, q.push(v);
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> t;
  while(t--) {
    cin >> n >> m >> a >> b >> c;
    
    for(int i = 1; i <= n; i++) {
      dista[i] = distb[i] = distc[i] = INF;
      adj[i].clear();
    }

    for(int i = 1; i <= m; i++) cin >> p[i];
    sort(p+1, p+m+1);
    
    int u, v;

    for(int i = 1; i <= m; i++) {
      ps[i] = ps[i-1] + 1ll*p[i];
      cin >> u >> v;
      adj[u].pb(v);
      adj[v].pb(u);
    }

    bfs(a, dista);
    bfs(b, distb);
    bfs(c, distc);

    ll ans = LINF;
    for(int i = 1; i <= n; i++) {
      ll tot = dista[i] + distb[i] + distc[i];
      if(tot > m) continue;
      ans = min(ans, ps[tot] + ps[distb[i]]);
    }

    cout << ans << "\n";
  }
}

