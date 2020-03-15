#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n, q, esc, par[N], sz[N];
map<string, int> id;
string a, b;

int find(string a){
  int x = id[a];
  while(par[x] != x) x = par[x];
  return x;
}

bool isSame(string a, string b){
  return find(a) == find(b);
}

void unite(string a, string b){
  if(isSame(a, b)) return;
  int x = find(a), y = find(b);
  if(sz[x] < sz[y]) swap(x, y);
  sz[x] += sz[y], par[y] = x;
}


int main(){
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n >> q;
  for(int i = 0; i < n; i++) par[i] = i, sz[i] = 1;
  for(int i = 0; i < n; i++){
    cin >> a;
    id[a] = i;
  }
  while(q--){
    cin >> esc >> a >> b;
    if(esc == 1) unite(a, b);
    else cout << (isSame(a, b) ? "yes" : "no") << "\n";
  }
}
