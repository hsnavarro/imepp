// Khun (Maximum Bipartite Matching) - O(VE)

int n, cnt, vis[N], match[N], ans;

bool find(int x){
  if(vis[x] == cnt) return false;
  vis[x] = cnt;
  for(auto u : adj[x]) if(!match[u] or find(match[u])) return match[u] = x;
  return false;
}

// Maximum Independent Set on bipartite graph
// MIS  = V - MATCH

// Minimum Vertex Cover  
// MVC = MATCH

// Minimum Path Cover on DAG
// MPC = V - MATCH

// TIP: If you don't know the sides of the bipartite graph, 
// run kuhn for all nodes and match = ans/2;

// in main (only for one of the sides)
for(int i = 1; i <= n; i++) ++cnt, ans += find(i);
