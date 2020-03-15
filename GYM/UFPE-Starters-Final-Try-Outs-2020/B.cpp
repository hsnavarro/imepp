#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

int n, st[4*N], m, q, val, esc, l, r, x;
map<string, int> mp;
string s;
vector<string> in;

void update(int i, int v, int p = 1, int l = 1, int r = n){
  if(l == r) { st[p] = v; return; }
  if(i <= (l+r)/2) update(i, v, 2*p, l, (l+r)/2);
  else update(i, v, 2*p+1, (l+r)/2+1, r);
  st[p] = st[2*p] + st[2*p+1];
}

int query(int i, int j, int p = 1, int l = 1, int r = n){
  if(r < i or j < l) return 0;
  if(i <= l and r <= j) return st[p];
  return query(i, j, 2*p, l, (l+r)/2) + query(i, j, 2*p+1, (l+r)/2+1, r);
}

int main(){
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n >> m >> q;
  for(int i = 0; i < n; i++) cin >> s, in.push_back(s);
  for(int i = 0; i < m; i++){
    cin >> s >> val;
    mp[s] = val;
  }
  for(int i = 0; i < in.size(); i++) update(i+1, mp[in[i]]); 
  for(int i = 0; i < q; i++){
    cin >> esc;
    if(esc == 1) {
      cin >> x >> s;
      update(x, mp[s]);
    }
    else {
      cin >> l >> r;
      int sum = query(l, r);
      if(2*sum <= 1ll*60*(r-l+1)) cout << "NO\n";
      else cout << "YES\n";
    }
  }
}
