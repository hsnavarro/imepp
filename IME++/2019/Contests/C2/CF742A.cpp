#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;

ll fexp(ll b, ll e, ll mod){
  ll ans = 1;
  while(e){
    if(e & 1) ans = (ans*b) % mod;
    e >>= 1, b = (b*b)%mod;
  }
  return ans;
}

int main(){
  scanf("%d", &n);
  printf("%lld\n", fexp(1378, n, 10));
}
