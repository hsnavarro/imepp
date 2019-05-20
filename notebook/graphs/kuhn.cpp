// Khun (Maximum Bipartite Matching) - O(VE)

int n, cnt, vis[N], match[N], ans;

bool find(int x){
  if(vis[x] == cnt) return false;
  vis[x] = cnt;
  for(auto u : adj[x]) if(!match[u] or find(match[u])) return match[u] = x;
  return false;
}

// in main
for(int i = 1; i <= n; i++) ++cnt, ans += find(i);
