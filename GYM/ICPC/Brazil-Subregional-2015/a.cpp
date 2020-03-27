#include <bits/stdc++.h>
using namespace std;

#define int long long
const int INF = 0x3f3f3f3f3f3f3f3f;
const int N = 1e4 + 5;

int c, v, a, b, w, dist[N][2];
vector<pair<int, int>> adj[N];
priority_queue<pair<int, pair<int, int>> > pq;

void dij(int s){
  memset(dist, 63, sizeof dist);
  dist[s][0] = 0;
  pq.push({0, {s, 0}});
  while(pq.size()){
    int ud = -pq.top().first;
    int u = pq.top().second.first;
    int isOdd = pq.top().second.second;
    pq.pop();

    if(ud > dist[u][isOdd]) continue;
    for(auto x : adj[u]){
      int v = x.first;
      int w = x.second;
      if(dist[u][isOdd] + w < dist[v][1 - isOdd]){
        dist[v][1 - isOdd] = w + dist[u][isOdd];
        pq.push({-dist[v][1 - isOdd], {v, 1 - isOdd}});
      }
    }
  }
}


int32_t main(){
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> c >> v;
  while(v--){
    cin >> a >> b >> w;
    adj[a].push_back({b, w});
    adj[b].push_back({a, w});
  }
  dij(1);
  cout << (dist[c][0] == INF ? -1 : dist[c][0]) << "\n";
}
