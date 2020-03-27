#include <bits/stdc++.h>
using namespace std;

const int N = 1000 + 5;

int m, n, k, x[N], y[N], r[N], sz[N], par[N];
vector<int> e, d, c, b;

int find(int a){ return par[a] == a ? a : par[a] = find(par[a]); }

void unite(int a, int b){
  a = find(a), b = find(b);
  if(a == b) return;
  if(sz[a] < sz[b]) swap(a, b);
  par[b] = a, sz[a] += sz[b];
}

int cond(int a, int b){
  int dist = (x[a]-x[b])*(x[a]-x[b]) + (y[a]-y[b])*(y[a]-y[b]);
  return dist <= (r[a]+r[b])*(r[a]+r[b]);
}

int32_t main(){
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> m >> n >> k;
  for(int i = 1; i <= k; i++){
    sz[i] = 1, par[i] = i;
    cin >> x[i] >> y[i] >> r[i];
  }

  for(int i = 1; i <= k; i++){
    if(x[i] - r[i] <= 0) e.push_back(i);
    if(x[i] + r[i] >= m) d.push_back(i);
    if(y[i] + r[i] >= n) c.push_back(i);
    if(y[i] - r[i] <= 0) b.push_back(i);
  }

  for(int i = 1; i <= k; i++){
    for(int j = 1; j <= k; j++){
      if(cond(i, j)) unite(i, j);
    }
  }
  int cond = 1;

  for(auto x : e){
    for(auto y : d)
      if(find(x) == find(y)) cond = 0;
    for(auto y : b)
      if(find(x) == find(y)) cond = 0;
  }

  for(auto x : c){
    for(auto y : b)
      if(find(x) == find(y)) cond = 0;
    for(auto y : d)
      if(find(x) == find(y)) cond = 0;
  }

  cout << (cond ? "S\n" : "N\n");
}
