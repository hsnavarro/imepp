#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const int N = 1000 + 5;

int n, m, a, b, dist[N], mx = -INF;
vector<int> adj[N];

void bfs(int x){
  memset(dist, 63, sizeof dist);
  queue<int> q;
  dist[x] = 0;
  q.push(x);
  while(q.size()){
    int v = q.front();
    q.pop();
    for(auto u : adj[v]) if(dist[u] == INF) dist[u] = dist[v] + 1, q.push(u);
  }
  for(int i = 1; i <= n; i++) mx = max(mx, dist[i]);
}

int main(){
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n >> m;
  while(m--){
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  for(int i = 1; i <= n; i++) bfs(i);
  if(mx == INF) cout << "=[" << endl;
  else cout << "=] " << mx << endl;
}
