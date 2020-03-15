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

const int N = 2e5 + 5;

ll n, a, b, k, h[N], ans;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n >> a >> b >> k;
  for(int i = 0; i < n; i++) {
    cin >> h[i];
    ll cte = h[i]/(a+b);
    if(h[i] % (a+b) == 0) cte--;
    if(cte > 0) h[i] -= cte*(a+b);
  }
  sort(h, h+n);

  //for(int i = 0; i < n; i++) {
  //  cout << "i, h[i] " << i << " " << h[i] << "\n";
  //}

  for(int i = 0; i < n; i++) {
    if(h[i] - a <= 0) ans++;
    else if(k > 0) {
      ll sub = (h[i] - a)/a;
      if((h[i] - a) % a != 0) sub++;
      if(k - sub >= 0) k -= sub, ans++;
    }
  }
  cout << ans << "\n";

}
