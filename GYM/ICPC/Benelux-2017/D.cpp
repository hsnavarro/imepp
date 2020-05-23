#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define pb push_back

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;

#define db(x) cerr << #x << " == " << 
#define _ << ", " << 

const int N = 1e5 + 5;
int n, m;
ll dist[N];
vector<pair<int, ll>> adj[N];

void dijkstra() {
  memset(dist, 63, sizeof dist);
  priority_queue<pair<ll, int>> pq;
  dist[1] = 0;
  pq.push({0, 1});
  while(pq.size()) {
    ll ud = -pq.top().st;
    int u = pq.top().nd;
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
}

int vis[N], par[N];

void dfs(int u = 0, int p = -1) {
  if(p != -1) par[u] = p;
  vis[u] = 1;
  for(auto x : adj[u]) {
    int v = x.st;
    ll w = x.nd;
    if(vis[v]) continue;
    if(dist[u] == dist[v] + w) continue;
    dfs(v, u);
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n >> m;
  int a, b;
  ll w;
  for(int i = 0; i < m; i++) {
    cin >> a >> b >> w;
    adj[a].pb({b, w});
    adj[b].pb({a, w});
  }
  dijkstra();
  dfs();
  if(!vis[1]) cout << "impossible\n";
  else {
    vector<int> path;
    path.pb(1);
    int u = 1;
    while(u) u = par[u], path.pb(u);
    reverse(path.begin(), path.end());
  
    cout << path.size() << " ";
    for(int i = 0; i < path.size(); i++) cout << path[i] << " \n"[i == path.size() - 1];
  }
}
