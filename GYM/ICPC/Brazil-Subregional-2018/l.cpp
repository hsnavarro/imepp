#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
const int M = 20 + 5;

int n, q, a, b, c, d, h[N], par[N], anc[N][M];
vector<int> adj[N];

void dfs(int x = 1){ 
  if(x != par[x]) h[x] = h[par[x]] + 1;
  for(auto v : adj[x]) if(v != par[x]) par[v] = x, dfs(v); 
}

void build(){
  par[1] = 1;
  dfs();
  for(int i = 1; i <= n; i++) anc[i][0] = par[i];
  for(int j = 0; j + 1 < M; j++){
    for(int i = 1; i <= n; i++){
      anc[i][j+1] = anc[anc[i][j]][j];
    }
  }
}

int lca(int a, int b){
  if(h[a] < h[b]) swap(a, b);
  for(int i = M-1; i >= 0; i--){
    if(h[a] - (1 << i) >= h[b]) a = anc[a][i];
  }

  if(a == b) return a;
  
  for(int i = M-1; i >= 0; i--){
    if(anc[a][i] != anc[b][i]) a = anc[a][i], b = anc[b][i];
  }
  return anc[a][0];
}

int dist(int a, int b){
  return h[a] + h[b] - 2*h[lca(a, b)];
}

int main(){
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n >> q;
  for(int i = 0; i < n-1; i++){
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  build();
  while(q--){
    cin >> a >> b >> c >> d;
    int op1 = dist(a, b) + dist(c, d);
    int op2 = min(dist(a, d) + dist(b, c), dist(a, c) + dist(b, d));
    if(op1 < op2) cout << "0\n";
    else cout << (op1-op2)/2+1 << "\n";
  }
}
