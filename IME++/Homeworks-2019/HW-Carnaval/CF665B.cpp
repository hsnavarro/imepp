#include <bits/stdc++.h>
using namespace std;

int n, m, k, ans, a;
vector<int> mk, it;

void change(int x){
  vector<int> aux;
  int idx, cond = 0, t = 0;
  for(int i = 0; i < mk.size(); i++,  t++) {
    if(mk[i] == x) {idx = i; break; }
  }
  ans += t+1;
  aux.push_back(x);
  for(int i = 0; i < mk.size(); i++) if(i != idx) aux.push_back(mk[i]);
  mk = aux;
}

int main(){
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n >> m >> k;
  mk.resize(k);
  for(int i = 0; i < k; i++) cin >> mk[i];
  while(n--){
    for(int i = 0; i < m; i++) {
      cin >> a;
      change(a);
    }
  }
  cout << ans << endl;
}
