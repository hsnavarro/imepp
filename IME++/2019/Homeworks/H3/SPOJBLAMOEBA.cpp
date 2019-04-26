#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MOD = 1e9+7;

ll t, N, M;

ll fexp(ll b, ll e){
  ll ans = 1;
  while(e){
    if(e & 1) ans = ans*b%MOD;
    b = b*b%MOD, e >>= 1;
  }
  return ans;
}

int main(){
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> t;
  while(t--){
    cin >> M >> N;
    ll y = fexp(M, N);
    ll x = (y - 1)*fexp(M-1, MOD-2)%MOD;;
    cout << x << " " << y << endl;
  }
}
