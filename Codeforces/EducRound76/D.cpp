#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
const int INF = 0x3f3f3f3f;

int t, n, m, p, s, st[4*N], mons[N];
vector<pair<int, int>> her, sch;

void build(int p = 1, int l = 1, int r = n){
  if(l == r) { st[p] = mons[l]; return; }
  build(2*p, l, (l+r)/2);
  build(2*p+1, (l+r)/2+1, r);
  st[p] = max(st[2*p], st[2*p+1]);
}

int query(int i, int j, int p = 1, int l = 1, int r = n){
  if(r < i or l > j) return -INF;
  if(i <= l and r <= j) return st[p];
  return max(query(i, j, 2*p, l, (l+r)/2), 
             query(i, j, 2*p+1, (l+r)/2+1, r));
}

bool test(int i, int x){
  if(!x) return true;
  int mx1 = query(i, min(i+x-1, n));
  pair<int, int> ax = {mx1, 0};
  int pos = lower_bound(sch.begin(), sch.end(), ax) - sch.begin();
  if(pos == sch.size()) return false;
  return sch[pos].second >= x;
}

int bin(int i, int l = 0, int r = n){
  int mid;
  while(l != r){
    mid = (l+r)/2;
    if(test(i, mid)) l = mid+1;
    else r = mid;
  }
  if(!test(i, l)) l--;
  return l;
}

int main(){
  scanf("%d", &t);
  while(t--){
    her.clear(), sch.clear();
    scanf("%d", &n);
    for(int i = 0; i <= 4*n; i++) st[i] = -INF;
    for(int i = 1; i <= n; i++) scanf("%d", &mons[i]);
    build();
    scanf("%d", &m);
    for(int i = 1; i <= m; i++){
      scanf("%d%d", &p, &s);
      her.push_back({p, s});
    }
    sort(her.begin(), her.end());
    int mx = 0;
    for(int i = her.size() - 1; i >= 0; i--){
      mx = max(mx, her[i].second);
      sch.push_back({her[i].first, mx});
    }
    sort(sch.begin(), sch.end());

    int pos = 1, ok = 1, cnt = 0;
    while(pos <= n){
      int pass = bin(pos);
      if(!pass) { ok = 0; break; }
      cnt++, pos += pass;
    }
    printf("%d\n", ok ? cnt : -1);
  }
}
