// 2-SAT - O(V + E)

const int M = 2*N + 5;

int n, vis[M], comp[M];
vector<int> adj[M], adji[M], st;
vector<int> ans;

// For each variable x, we create two nodes in the graph: u and !u
// If the variable has index i, the index of u and !u are: 2*i and 2*i+1
// Add statement u or v => !u -> v or !v -> u 
void add(int u, int v){
  adj[u^1].push_back(v);
  adj[v^1].push_back(u);
  adji[v].push_back(u^1);
  adji[u].push_back(v^1);
}

void dfs1(int x){
  vis[x] = 1;
  for(auto v : adj[x]) if(!vis[v]) dfs1(v);
  st.push_back(x);
}

void dfs2(int x, int i){
  vis[x] = 0;
  comp[x] = i;
  for(auto v : adji[x]) if(vis[v]) dfs2(v, i);
}

bool sat(){
  for(int i = 2; i <= 2*n+1; i++) if(!vis[i]) dfs1(i);
  int idx = 1;
  while(st.size()){
    int x = st.back(); st.pop_back();
    if(vis[x]) dfs2(x, idx++);
  }
  ans.assign(n/2, 0);
  for(int i = 2; i <= 2*n+1; i += 2){
    if(comp[i] == comp[i+1]) return false;
    ans[i/2] = comp[i] > comp[i+1];
  }
  return true;
}

