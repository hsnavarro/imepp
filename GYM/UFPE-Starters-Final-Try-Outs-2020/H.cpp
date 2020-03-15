#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second

const int N = 1e5 + 5;

typedef long long ll;

int n, m, k, a, b;
ll w, t[N], dist[N];
vector<pair<int, ll>> adj[N];
priority_queue<pair<ll, int>> pq;
vector<int> start;

void dijkstra(){
    memset(dist, 63, sizeof dist);
    for(auto x : start) dist[x] = t[x], pq.push({dist[x], x});
    while(!pq.empty()){
        int ud = -pq.top().st;
        int u = pq.top().nd;
        pq.pop();
        if(dist[u] < ud) continue;
        for(auto x : adj[u]){
            int v = x.st;
            int w = x.nd + t[v];
            if(dist[u] + w < dist[v]){
                dist[v] = dist[u] + w;
                pq.push({-dist[v], v});
            }
        }
    }
}


int main(){
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n >> m >> k;
  while(m--){
    cin >> a >> b >> w;
    adj[a].push_back({b, w});
    adj[b].push_back({a, w});
  }
  for(int i = 1; i <= n; i++) cin >> t[i];
  start.resize(k);
  for(int i = 0; i < k; i++) cin >> start[i];
  dijkstra();

  for(int i = 1; i <= n; i++) cout << dist[i] << "\n";
}
