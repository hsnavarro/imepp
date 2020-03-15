#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e6 + 5;
const ll MOD = 998244353;

ll ans;

ll fexp(ll b, ll e) {
  ll ans = 1;
  while(e) {
    if(e & 1ll) ans = (ans*b) % MOD;
    b = (b*b) % MOD;
    e = e/2;
  }
  return ans;
}

ll calc(ll i, ll j) { return (i*fexp(j, MOD-2)) % MOD; }

void find_ans(ll e){
  for(ll i = 1; i <= N; i++) {
    for(ll j = 1; j <= N; j++) {
      if(calc(i, j) == e) {
        cout << i << " " << j << endl;
        exit(0);
      }
    }
  }
}

int main(){
  //cin >> ans;
  //find_ans(ans);
  cout << calc(248405940, 1523515392) << endl;
  return 0;
}
