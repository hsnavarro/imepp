#include <bits/stdc++.h>
using namespace std;

const int N = 150000 + 5;
const int INF = 0x3f3f3f3f;

int t, mn, n, a[N], ans;

int32_t main(){
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> t;
  while(t--){
    mn = INF, ans = 0;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = n-1; i >= 0; i--) {
      if(a[i] > mn) ans++;
      mn = min(a[i], mn);
    }
    cout << ans << "\n";
  }
}
