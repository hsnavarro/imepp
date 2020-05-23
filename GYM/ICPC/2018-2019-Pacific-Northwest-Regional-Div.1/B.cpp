#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define pb push_back

typedef long long ll;

const int N = 1e7 + 5;

ll ans, a, b, c, d;
ll mob[N], cmp[N];

void mobius() {
  for(int i = 1; i < N; i++) mob[i] = 1;
  for(ll i = 2; i < N; i++) if(!cmp[i]) {
    for(ll j = i; j < N; j += i) cmp[j] = 1, mob[j] *= -1;
    for(ll j = i*i; j < N; j += i*i) mob[j] = 0;
  }
}


int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  mobius();
  cin >> a >> b >> c >> d;
  ll mdc = __gcd(b, d);
  for(ll i = 1; i <= mdc; i++)
    ans += mob[i] * (b/i - (a-1)/i) * (d/i - (c-1)/i);
  cout << ans << "\n";
}
