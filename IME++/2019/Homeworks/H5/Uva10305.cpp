#include <bits/stdc++.h>
using namespace std;

int n, m, a, b, vis[105];
vector<int> adj[105], ans;

void dfs(int x){
  vis[x] = 1;
  for(auto v : adj[x]) if(!vis[v]) dfs(v);
  ans.push_back(x);
}

int main(){
  ios_base::sync_with_stdio(0), cin.tie(0);
  while(cin >> n >> m and n or m){
    memset(vis, 0, sizeof vis);
    for(int i = 0; i < 105; i++) adj[i].clear();
    while(m--){
      cin >> a >> b;
      adj[a].push_back(b);
    }
    for(int i = 1; i <= n; i++) if(!vis[i]) dfs(i);
    while(ans.size()) cout << ans.back() << " ", ans.pop_back();
    cout << endl;
  }
}
