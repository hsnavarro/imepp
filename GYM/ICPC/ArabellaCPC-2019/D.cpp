#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;

int n, m, a[N], b, mdc;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n >> m;
  for(int i = 0; i < n; i++) cin >> a[i];
  for(int i = 0; i < m; i++) cin >> b, mdc = __gcd(mdc, b);
  int val = a[0] % mdc;
  for(int i = 0; i < n; i++) if(a[i] % mdc != val) return cout << "No\n", 0;
  cout << "Yes\n";
}
