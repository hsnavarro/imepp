#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll MOD = 1e9 + 7;
const int N = 1e3 + 1e2;

ll n, m, fat[N];

ll inv(ll b) {
  ll ans = 1, e = MOD - 2;
  while(e) {
    if(e & 1) ans = (ans*b) % MOD;
    b = (b*b) % MOD;
    e = e/2;
  }
  return ans;
}

ll mult(ll a, ll b) { return (a*b) % MOD; } 

ll comb(ll a, ll b) {
  return mult(fat[a], mult(inv(fat[a-b]), inv(fat[b])));
}

int main(){
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n >> m;
  fat[0] = 1;
  for(int i = 1; i < N; i++) fat[i] = (1ll*i*fat[i-1]) % MOD;
  cout << comb(n+2*m-1, 2*m) << "\n";
}
