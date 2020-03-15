#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
typedef long long ll;

int n;
ll a[N];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  ll mdc = 0, sum = 0, mx = 0;
  for(int i = 0; i < n; i++) cin >> a[i], mx = max(mx, a[i]);
  for(int i = 0; i < n; i++) mdc = __gcd(mdc, mx - a[i]);
  for(int i = 0; i < n; i++) sum += (mx - a[i])/mdc;
  cout << sum << " " << mdc << "\n";
}
