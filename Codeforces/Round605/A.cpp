#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second

typedef pair<int, int> pii;
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

ll q, a, b, c;

int main(){
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> q;

  while(q--){
    ll ans = LINF;
    cin >> a >> b >> c;
    for(ll i = -1; i <= 1; i++)
      for(ll j = -1; j <= 1; j++)
        for(ll k = -1; k <= 1; k++)
          ans = min(ans, abs(a + i - b - j) + abs(a + i - c - k) + abs(b + j - c - k));

    cout << ans << "\n";
  }
}
