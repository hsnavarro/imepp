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
typedef unsigned long long ull;
typedef long double ld;

typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;

const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e2+5;

int t, n;
ll dist[N], p[N], x[N], y[N];
vector<pair<int, ll>> adj[N];

ll calc(int i, int j) {
  ll dist_euc = (x[i] - x[j])*(x[i] - x[j]) + (y[i] - y[j])*(y[i] - y[j]); 
  ll dist_man = abs(x[i] - x[j]) + abs(y[i] - y[j]);
  if(i != n+2 and j != n+2 and i != n+1 and p[i]*p[i] >= dist_euc) return min(dist_man, 2ll);
  return dist_man;
}

ll dijkstra() {
  priority_queue<pair<ll, int>> pq;
  dist[n+1] = 0;
  pq.push({0, n+1});
  while(pq.size()) {
    int u = pq.top().nd;
    ll ud = -pq.top().st;
    pq.pop();
    if(ud > dist[u]) continue;
    for(auto x : adj[u]) {
      int v = x.st;
      ll w = x.nd;
      if(dist[u] + w < dist[v]) {
        dist[v] = dist[u] + w;
        pq.push({-dist[v], v});
      }
    }
  }
  return dist[n+2];
}


int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> t;
  while(t--) {
    cin >> n;
    memset(dist, 63, sizeof dist);
    for(int i = 0; i <= n+2; i++) adj[i].clear();

    for(int i = 1; i <= n; i++) cin >> x[i] >> y[i] >> p[i];
    cin >> x[n+1] >> y[n+1] >> x[n+2] >> y[n+2];
    
    for(int i = 1; i <= n+2; i++) {
      for(int j = 1; j <= n+2; j++) if(i != j) adj[i].pb({j, calc(i, j)});
    }

    cout << dijkstra() << "\n";
  }
}

