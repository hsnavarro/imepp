#include <bits/stdc++.h>
using namespace std;

const int N = 1e6;

int q, n, m, ok;
typedef long long ll;

ll fexp(ll b, ll e, ll mod){
  ll ans = 1;
  while(e){
    if(e & 1) ans = (ans*b)%mod;
    b = (b*b)%mod;
    e = e/2;
  }
  return ans;
}

int main(){
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> q;
  srand(time(0));
  while(q--){
    ok = 0;
    cin >> n >> m;
    for(int i = 0; i <= 800; i++){
      int x = rand() % (N+1);
      if(fexp(n, x, m) == 1) {
        cout << x << "\n";
        ok = 1;
        break;
      }
    }
    if(ok) continue;
    cout << -1 << "\n";
  }
}
