#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const int N = 1e4 + 5;
int n, a, b, dist[N];
vector<int> adj[N];

void dfs(int x, int h){
  dist[x] = h;
  for(auto v : adj[x]) if(dist[v] == INF) dfs(v, h+1);
}

int main(){
  memset(dist, 63, sizeof dist);
  scanf("%d", &n);
  for(int i = 1; i < n; i++){
    scanf("%d%d", &a, &b);
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  dfs(1, 0);
  int maxdist = -INF, node;
  for(int i = 1; i <= n; i++) 
    if(dist[i] > maxdist) maxdist = dist[i], node = i;

  memset(dist, 63, sizeof dist);
  dfs(node, 0);
  maxdist = -INF;
  for(int i = 1; i <= n; i++) maxdist = max(maxdist, dist[i]);
  printf("%d\n", maxdist);
}
