#include <bits/stdc++.h>
using namespace std;
 
const int N = 1e5 + 5;
 
#define st first
#define nd second
 
int n, k, a, ans, par[N], vis[N];
pair<int, int> h[N];
// height, who
vector<int> adj[N];
priority_queue<pair<int, int>> pq;
 
void dfs(int x, int p = -1){
  par[x] = p;
  pair<int, int> mx = {0, x};
  for(auto v : adj[x])
    if(v != p) dfs(v, x), mx = max(mx, h[v]);
  h[x] = {mx.st + 1, mx.nd};
}
 
void up(int x){
  vis[x] = 1;
  for(auto v : adj[x]) if(!vis[v] and v != par[x]) pq.push(h[v]);
  if(par[x] != -1 and !vis[par[x]]) up(par[x]);
}
 
int32_t main(){
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n >> k;
  for(int i = 2; i <= n; i++) {
    cin >> a;
    adj[i].push_back(a);
    adj[a].push_back(i);
  }
  dfs(1);
  pq.push(h[1]);
  for(int i = 0; i < k and pq.size(); i++){
    pair<int, int> tp = pq.top();
    pq.pop();
    ans += tp.st;
    up(tp.nd);
  }
  cout << ans << "\n";
}
