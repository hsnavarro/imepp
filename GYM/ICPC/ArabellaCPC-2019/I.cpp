#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 3e5 + 5;

int n;
ll a[N], sum, ans;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  for(int i = 0; i < n; i++) cin >> a[i];
  sort(a, a+n);
  for(int k = 2, l = 0, r = n-1; k <= n; k++) {
    if(k % 2 == 0) sum += a[r--] - a[l++];
    ans += sum;
    cout << ans << " ";
  }
  cout << "\n";
}
