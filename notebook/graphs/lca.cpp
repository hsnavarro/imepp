// Lowest Common Ancestor - <O(nlog n), O(log n)>

const int N = 1e6;
const int M = 25; //m = log N

int anc[N][M], h[N], rt;
vector<int> adj[N];

void dfs(int x = rt, int p = -1, int ht = 0){
  anc[x][0] = p, h[x] = ht;
  for(auto v : adj[x]) if(v != p) dfs(v, x, ht+1);
}

void build(){
  dfs(), anc[rt][0] = rt;

  for(int j = 1; j < M; j++)
    for(int i = 1; i <= n; i++) // 1-indexed
      anc[i][j] = anc[anc[i][j-1]][j-1];
}

int lca(int u, int v){
  if(h[u] < h[v]) swap(u, v);
  for(int i = M-1; i >= 0; i--) if(h[u] - (1<<i) >= h[v]) u = anc[u][i];
  
  if(u == v) return u;
  for(int i = M-1; i >= 0; i--) if(anc[u][i] != anc[v][i])
    u = anc[u][i], v = anc[v][i];

  return anc[u][0];
}
