#include <bits/stdc++.h>
using namespace std;

const int N = 3e4 + 5;
int n, t, a, vis[N];
vector<int> adj[N];

void dfs(int v){
  vis[v] = 1;
  for(auto x : adj[v]) if(!vis[x]) dfs(x);
}

int main(){
  scanf("%d%d", &n, &t);
  for(int i = 1; i < n; i++) scanf("%d", &a), adj[i].push_back(i+a);
  dfs(1);
  printf("%s\n", vis[t] ? "YES" : "NO");
}
