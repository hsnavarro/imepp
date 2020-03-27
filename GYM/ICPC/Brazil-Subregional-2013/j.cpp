#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define pb push_back

typedef pair<int, int> pii;

const int INF = 0x3f3f3f3f;
const int N = 2e4 + 5; 
const int MAXP = 1e5 + 5;

int n, m, s, a, b, w, p, par[N], sz[N], his[N];
vector<pair<int, pii>> edge;

int find(int a, int peso) { 
  if(par[a] == a) return a;
  if(his[a] < peso) return a;
  return find(par[a], peso); 
}

int bin(int a, int b, int l = 0, int r = MAXP){
  int mid;
  while(l != r){
    mid = (l+r)/2;
    if(find(a, mid) == find(b, mid)) l = mid + 1;
    else r = mid;
  }
  return l ? l-1 : 0;
}

void unite(int a, int b, int peso){
  a = find(a, peso), b = find(b, peso);
  if(a == b) return;
  if(sz[a] < sz[b]) swap(a, b);
  sz[a] += sz[b], par[b] = a, his[b] = peso;
}

int32_t main(){
  ios_base::sync_with_stdio(0), cin.tie(0);
  while(cin >> n >> m >> s){
  for(int i = 1; i <= n; i++) par[i] = i, sz[i] = 1, his[i] = -1;
  for(int i = 0; i < m; i++){
    cin >> a >> b >> w;
    edge.pb({-w, {a, b}});
  }
  sort(edge.begin(), edge.end());
  for(auto x : edge) unite(x.nd.st, x.nd.nd, -x.st);
  for(int i = 0; i < s; i++){
    cin >> a >> b;
    cout << bin(a, b) << "\n";
  }
  edge.clear();
  }
} 
