#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
const int INF = 0x3f3f3f3f;

int n, q, esc, a, b, v[N], st1[4*N], st2[4*N], st3[4*N];

void buildsum(int p = 1, int l = 1, int r = n){
    if(l == r) { st1[p] = v[l]; return; }
    buildsum(2*p, l, (l+r)/2), buildsum(2*p + 1, (l+r)/2 + 1, r);
    st1[p] = st1[2*p] + st1[2*p + 1];
}

int querysum(int i, int j, int p = 1, int l = 1, int r = n){
    if(l >= i and j >= r) return st1[p];
    if(l > j or r < i) return 0;
    return 
      querysum(i, j, 2*p, l, (l+r)/2) +
      querysum(i, j, 2*p + 1, (l+r)/2 + 1, r);
}

void updatesum(int idx, int v, int p = 1, int l = 1, int r = n){
    if(l == r) { st1[p] = v; return; }
    if(idx <= (l+r)/2) updatesum(idx, v, 2*p, l, (l+r)/2);
    else updatesum(idx, v, 2*p + 1, (l+r)/2 + 1, r);
    st1[p] = st1[2*p] + st1[2*p + 1];
}

void buildmax(int p = 1, int l = 1, int r = n){
    if(l == r) { st2[p] = v[l]; return; }
    buildmax(2*p, l, (l+r)/2), buildmax(2*p + 1, (l+r)/2 + 1, r);
    st2[p] = max(st2[2*p], st2[2*p + 1]);
}

int querymax(int i, int j, int p = 1, int l = 1, int r = n){
    if(l >= i and j >= r) return st2[p];
    if(l > j or r < i) return -INF;
    return 
      max(querymax(i, j, 2*p, l, (l+r)/2), 
          querymax(i, j, 2*p + 1, (l+r)/2 + 1, r));
}

void updatemax(int idx, int v, int p = 1, int l = 1, int r = n){
    if(l == r) { st2[p] = v; return; }
    if(idx <= (l+r)/2) updatemax(idx, v, 2*p, l, (l+r)/2);
    else updatemax(idx, v, 2*p + 1, (l+r)/2 + 1, r);
    st2[p] = max(st2[2*p], st2[2*p + 1]);
}

void buildmin(int p = 1, int l = 1, int r = n){
    if(l == r) { st3[p] = v[l]; return; }
    buildmin(2*p, l, (l+r)/2), buildmin(2*p + 1, (l+r)/2 + 1, r);
    st3[p] = min(st3[2*p], st3[2*p + 1]);
}

int querymin(int i, int j, int p = 1, int l = 1, int r = n){
    if(l >= i and j >= r) return st3[p];
    if(l > j or r < i) return INF;
    return 
      min(querymin(i, j, 2*p, l, (l+r)/2), 
          querymin(i, j, 2*p + 1, (l+r)/2 + 1, r));
}

void updatemin(int idx, int v, int p = 1, int l = 1, int r = n){
    if(l == r) { st3[p] = v; return; }
    if(idx <= (l+r)/2) updatemin(idx, v, 2*p, l, (l+r)/2);
    else updatemin(idx, v, 2*p + 1, (l+r)/2 + 1, r);
    st3[p] = min(st3[2*p], st3[2*p + 1]);
}

int main(){
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n >> q;
  for(int i = 1; i <= n; i++) cin >> v[i];
  buildsum(), buildmax(), buildmin();
  while(q--){
    cin >> esc >> a >> b;
    if(esc == 1) cout << querysum(a, b)-querymax(a, b)-querymin(a, b) << endl;
    else updatesum(a, b), updatemin(a, b), updatemax(a, b);
  }
}
