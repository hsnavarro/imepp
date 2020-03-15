#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
const int INF = 0x3f3f3f3f;

#define st first
#define nd second
#define pb push_back

int n, m, x, y, cnt, mn, mx, isOpen, vis[N];
vector<int> adj[N];
vector<pair<int, int>> v;

void dfs(int x){
  vis[x] = 1;
  mx = max(mx, x), mn = min(mn, x);
  for(auto u : adj[x]) if(!vis[u]) dfs(u);
}

int main(){
  scanf("%d%d", &n, &m);
  for(int i = 0; i < m; i++){
    scanf("%d%d", &x, &y);
    adj[x].pb(y);
    adj[y].pb(x);
  }

  for(int i = 1; i <= n; i++) 
    if(!vis[i]) mn = INF, mx = -INF, dfs(i), v.pb({mn, 0}), v.pb({mx, 1});
  
  sort(v.begin(), v.end());
  for(auto x : v){
    if(x.nd) isOpen--;
    if(!x.nd and isOpen) cnt++;
    if(!x.nd) isOpen++;
  }

  printf("%d\n", cnt);
}
