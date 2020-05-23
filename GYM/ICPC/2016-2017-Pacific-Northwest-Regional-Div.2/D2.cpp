#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e5 + 5;

ll n, k, r, a[N];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n >> k >> r;
  ll ks;
  while(k--) {
    cin >> ks;
    a[ks]++;
  }

  ll sum = 0, ans = 0;
  for(int i = 0; i < n; i++) {
    sum += a[i];
    if(i >= r) sum -= a[i-r];
    if(i >= r-1) {
      if(!sum) {
        ans += 2;
        sum += 2;
        a[i] = 1;
        a[i-1] = 1;
      } else if(sum == 1) {
        ans++;
        sum++;
        a[i] ? a[i-1] = 1 : a[i] = 1;
      }
    }
  }
  cout << ans << "\n";
}
