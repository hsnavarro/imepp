// Dijkstra (with set) - O(ElogE)
// For interview purpose

int n, m, dist[N];
vector<pair<int, int>> adj[N];

void dijkstra(int s){
  memset(dist, 63, sizeof dist);
  set<pair<int, int>> edg;
  dist[s] = 0;
  edg.insert({0, s});
  while(edg.size()){
    pair<int, int> par = *(edg.begin());
    edg.erase(par);
    int v = par.second;
    for(auto x : adj[v]){
      int u = x.first;
      int w = x.second;
      if(dist[v] + w < dist[u]){
        edg.erase({dist[u], u});
        dist[u] = dist[v] + w;
        edg.insert({dist[u], u});
      }
    }
  }
}
