#include <bits/stdc++.h>
using namespace std;

const int N = 1e4+5;

int n, m, a, b, vis[N];
vector<int> adj[N];

void dfs(int x){
  vis[x] = 1;
  for(auto v : adj[x]) if(!vis[v]) dfs(v);
}

int main(){
  scanf("%d%d", &n, &m);
  for(int i = 0; i < m; i++){
    scanf("%d%d", &a, &b);
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  if(m != n-1) return printf("NO\n"), 0;
  dfs(1);
  for(int i = 1; i <= n; i++) if(!vis[i]) return printf("NO\n"), 0;
  printf("YES\n");
}
