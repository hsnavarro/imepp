#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define pb push_back

typedef long long ll;
typedef long double ld;

ld k, p, x;

ld eval(ll m) {
  return m*x + (k*p)/m;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> k >> p >> x;
  ll m = sqrt((k*p)/x);
  ld a = eval(m), b = eval(m+1), c = 1e14;
  if(m-1 >= 0) c = eval(m-1);
  cout << fixed << setprecision(3) << min({a, b, c}) << "\n";
}
