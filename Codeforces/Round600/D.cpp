#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

int n, m, x, y, cnt, par[N], mx[N], mn[N], sz[N];
set<int> p;

int find(int a) { return a == par[a] ? a : par[a] = find(par[a]); }

void unite(int a, int b){
    a = find(a), b = find(b);
    if(sz[a] < sz[b]) swap(a, b);
    sz[a] += sz[b], par[b] = a; 
    mx[a] = max(mx[b], mx[a]);
    mn[a] = min(mn[b], mn[a]);
}

int main(){
  scanf("%d%d", &n, &m);
  for(int i = 1; i <= n; i++) par[i] = i, sz[i] = 1, mn[i] = i, mx[i] = i;
  for(int i = 0; i < m; i++){
    scanf("%d%d", &x, &y);
    unite(x, y);
  }

  int pos = 1;
  while(pos <= n){
    int pr = find(pos), l = mn[pr], r = mx[pr];
    for(int i = l; i <= r; i++) if(find(l) != find(i)) cnt++, unite(l, i);
    pos = r+1;
  }

  printf("%d\n", cnt);
}
