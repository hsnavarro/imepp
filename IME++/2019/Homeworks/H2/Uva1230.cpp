#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll x, y, n, c;

ll fexp(ll b, ll e, ll mod){
  ll ans = 1;
  while(e){
    if(e & 1) ans = (ans*b)%mod;
    b = (b*b)%mod; e >>= 1;
  }
  return ans;
}

int main(){
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> c;
  while(c--){
    cin >> x >> y >> n;
    cout << fexp(x, y, n) << endl;
  }
  cin >> c;
}
