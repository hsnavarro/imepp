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

int t, n, cnt, x;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> t;
  while(t--) {
    cin >> n;
    int aux = n;
    cnt = 0;
    while(n--) {
      cin >> x;
      if(x & 1) cnt++;
    }
    if(cnt == aux and (aux & 1)) cout << "YES\n";
    else if(cnt != aux and cnt > 0) cout << "YES\n";
    else cout << "NO\n";
  }
}
