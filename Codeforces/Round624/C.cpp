#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define pb push_back

typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const ld EPS = 1e-9;
const int MOD = 1e9+7;

const int N = 2e5 + 5;

int t;
ll n, m, ps[N][26], ans[26], p[N];
string s;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> t;
  while(t--) {
    cin >> n >> m;
    cin >> s;
    for(int i = 0; i < m; i++) cin >> p[i];
    for(int i = 0; i < 26; i++) {
      ans[i] = 0;
      for(int j = 0; j <= n; j++) ps[j][i] = 0;
    }

    for(int i = 0; i < 26; i++) {
      for(int j = 1; j <= n; j++) ps[j][i] = ps[j-1][i] + ((s[j-1] - 'a') == i);
    }

    for(int i = 0; i < 26; i++) {
      for(int j = 0; j < m; j++) ans[i] += ps[p[j]][i];
      ans[i] += ps[n][i];
      cout << ans[i] << " ";
    }
    cout << "\n";
  }
}
