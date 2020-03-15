#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;

typedef long long ll;
ll n, q, m, phi[N];

int main(){
  ios_base::sync_with_stdio(0), cin.tie(0);

  phi[1] = 1;
  for (ll i = 2; i < N; ++i) if (!phi[i]) for (ll j = i; j < N; j+=i) {
    if (!phi[j]) phi[j] = j;
    phi[j] -= phi[j]/i ;
  }

  cin >> q;
  while(q--){
    cin >> n >> m;
    if(__gcd(n, m) != 1) cout << -1 << "\n";
    else cout << phi[m] << "\n";
  }

}
