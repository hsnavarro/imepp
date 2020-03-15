#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n, a[N], suf[N], pref[N];
int mx, idx;

int func(int x, int y) { return (x|y) - y; }

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  for(int i = 0; i < n; i++) cin >> a[i];
  for(int i = 0; i < n; i++) pref[i] = (i-1 >= 0 ? pref[i-1] : 0) | a[i];
  for(int i = n-1; i >= 0; i--) suf[i] = (i+1 < n ? suf[i+1] : 0) | a[i];

  for(int i = 0; i < n; i++) {
    int s = 0, p = 0;
    if(i-1 >= 0) p = pref[i-1];
    if(i+1 < n) s = suf[i+1];
    if(func(a[i], p | s) > mx) mx = func(a[i], p | s), idx = i;
  }
  cout << a[idx] << " ";
  for(int i = 0; i < n; i++) if(i != idx) cout << a[i] << " ";
  cout << "\n";
}
