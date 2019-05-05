#include <bits/stdc++.h>
using namespace std;

const int N = 1e6+10;

int idx, t, l, n, cnt, cmp[N], prod[N];
vector<int> resp;
set<int> p, aux;
map<int, int> pos;

void primes() {
  for (int i = 2; i < N; i++) if (!cmp[i]){
    p.insert(i);
    for (long long j = 1ll*i*i; j < N; j+=i) cmp[j]=1;
 }
}

bool test(int x){
  resp.push_back(x), resp.push_back(prod[0]/x);
  for(int i = 1; i < l; i++){
    if(prod[i] % resp.back() != 0){ resp.clear();  return false; }
    resp.push_back(prod[i]/resp.back());
  }
  return true;
}

void reset(){
  idx = 0;
  memset(prod, 0, sizeof prod);
  resp.clear(), pos.clear(), aux.clear();
}

int main(){
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> t;
  primes();
  while(t-- and ++cnt){
    cin >> n >> l;
    reset();
    for(int i = 0; i < l; i++) cin >> prod[i];
    for(auto x : p) if(prod[0] % x == 0) if(test(x)) break;
    
    for(auto x : resp) aux.insert(x);
    for(auto x : aux) pos[x] = idx++;
    cout << "Case #" << cnt << ": ";
    for(auto x : resp) cout << char(pos[x] - 0 + 'A');
    cout << endl;
  }
}
