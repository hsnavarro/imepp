#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

vector<int> adj[N];
int n, m, a, b, vis[N], c[N];
pair<int, int> edg[N];

void dfs(int x){
  vis[x] = 1;
  for(auto v : adj[x]){
    if(c[v] != -1 and c[v] == c[x]) cout << "NO" << endl, exit(0);
    if(!vis[v]) c[v] = c[x]^1, dfs(v);
  }
}

int main(){
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n >> m;
  for(int i = 0; i < m; i++){
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
    edg[i] = {a, b};
  }
  memset(c, -1, sizeof c);
  c[1] = 1;
  dfs(1);
  cout << "YES" << endl;
  for(int i = 0; i < m; i++) cout << c[edg[i].first];
  cout << endl;
}
