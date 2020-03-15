#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
const int INF = 0x3f3f3f3f;

int n, a, b, par[N], dist[N];
vector<int> adj[N], diam;
int mx = -1, node;
set<pair<int, int>> s;

void dfs(int u, int p, int h) {
  if(h > mx) mx = h, node = u;
  if(p != -1) par[u] = p;
  for(auto v : adj[u]) 
    if(v != p) dfs(v, u, h+1);
}

int bfs() {
  int node, mx = -1;
  queue<int> q;
  memset(dist, INF, sizeof dist);
  for(auto x : diam) {
    dist[x] = 0;
    if(dist[x] > mx) mx = dist[x], node = x;
    q.push(x);
  }
  while(q.size()) {
    int u = q.front();
    q.pop();
    for(auto v : adj[u]) {
      if(dist[v] == INF) {
        dist[v] = dist[u] + 1;
        if(dist[v] > mx) mx = dist[v], node = v;
        q.push(v);
      }
    }
  }
  return node;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  for(int i = 0; i < n-1; i++) {
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  dfs(1, -1, 0);
  int start = node;
  mx = -1;
  dfs(start, -1, 0);
  int x = node;
  diam.push_back(x);
  while(x != start) {
    s.insert({min(x, par[x]), max(x, par[x])});
    x = par[x], diam.push_back(x);
  }
  int last = bfs();
  x = last;
  while(x != start) {
    s.insert({min(x, par[x]), max(x, par[x])});
    x = par[x];
  }
  
  cout << s.size() << "\n";
  if(last == start or last == node) {
    for(int i = 1; i <= n; i++) 
      if(i != start and i != node) { last = i; break; } 
  }
  cout << start << " " << node << " " << last << "\n";
}
