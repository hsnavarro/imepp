#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
int n, x, y, vis[2*N];
vector<int> adj[2*N], v;

void dfs(int x){
  vis[x] = 1;
  for(auto v : adj[x]) if(!vis[v]) dfs(v);
}

int main(){
  scanf("%d", &n);
  for(int i = 0; i < n; i++){
    scanf("%d%d", &x, &y);
    v.push_back(x);
    y += N;
    v.push_back(y);
    adj[x].push_back(y);
    adj[y].push_back(x);
  }

  int cnt = 0;
  for(auto x : v) if(!vis[x]) dfs(x), cnt++;
  printf("%d\n", cnt-1);
}
