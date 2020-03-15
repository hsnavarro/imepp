#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define pb push_back

typedef long long ll;
typedef pair<int, int> pii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9+7;

int t;
ll s, ans;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> t;
  while(t--) {
    ans = 0;
    cin >> s;
    ll x = s/10 * 10;
    if(!x) x = 1;
    while(s) {
      //cout << "x " << x << endl;
      ans += x;
      s = s + x/10 - x;
      x = s/10 * 10;
      if(!x) x = 1;
    }
    ans += s;
    cout << ans << "\n";
  }
}
