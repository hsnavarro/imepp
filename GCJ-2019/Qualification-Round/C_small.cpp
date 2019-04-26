#include <bits/stdc++.h>
using namespace std;

const int N = 1e6+10;

int idx, t, l, n, cnt, cmp[N], prod[N];
vector<int> resp;
set<int> p, res;
map<int, int> pos;

void primes() {
  for (long long i = 2; i < N; i++) if (!cmp[i]){
    for (long long  j = i*i; j < N; j+=i) cmp[j]=1;
 }
 for(int i = 2; i < N; i++) if(!cmp[i]) p.insert(i);
}


bool test(int x){
  resp.push_back(x), res.insert(x);
  resp.push_back(prod[0]/x), res.insert(prod[0]/x);
  
  for(int i = 1; i < l; i++){
    if(prod[i] % resp.back() != 0){ resp.clear(), res.clear(); return false; }
    res.insert(prod[i]/resp.back()), resp.push_back(prod[i]/resp.back());
  }
  if(res.size() != 26) { resp.clear(), res.clear(); return false; }
  return true;
}

void reset(){
  idx = 0;
  memset(prod, 0, sizeof prod);
  resp.clear(), res.clear(), pos.clear();
}

int32_t main(){
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> t;
  primes();
  while(t-- and ++cnt){
    cin >> n >> l;
    reset();
    for(int i = 0; i < l; i++) cin >> prod[i];
    for(auto x : p) if(prod[0] % x == 0){
      if(test(x)) break;
    }
    
    for(auto x : resp) cout << x << " ";
    cout << endl;
    for(auto x : res) pos[x] = idx++;
    cout << "Case #" << cnt << ": ";
    for(auto x : resp) cout << char(pos[x] - 0 + 'A');
    cout << endl;
  }
}
