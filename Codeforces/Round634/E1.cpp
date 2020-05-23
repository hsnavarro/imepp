#include <bits/stdc++.h>
using namespace std;

mt19937_64 llrand((int) chrono::steady_clock::now().time_since_epoch().count());

#define st first
#define nd second
#define pb push_back

#ifndef ONLINE_JUDGE
  #define db(x) cerr << #x << " == " << x << endl
  #define dbs(x) cerr << x << endl
  #define _ << ", " <<
#else
  #define db(x) ((void)0)
  #define dbs(x) ((void)0)
#endif

typedef long long ll;
typedef long double ld;

typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;

const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 2e3+5;

#define int long long

int t, n, a[N], pref[N][30], suf[N][30], maxs[30], maxf[30];

int32_t main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> t;
  while(t--) {
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];

    for(int i = 0; i <= n+1; i++)
      for(int j = 0; j <= 26; j++) pref[i][j] = suf[i][j] = 0;

    for(int i = 1; i <= n; i++) {
      for(int j = 1; j <= 26; j++) {
          pref[i][j] = (a[i] == j) + pref[i-1][j];
      }
    }

    for(int i = n; i >= 1; i--) {
      for(int j = 1; j <= 26; j++) {
        suf[i][j] = (a[i] == j) + suf[i+1][j];
      }
    }

    int mx = -1;
    for(int k = 1; k <= 26; k++) mx = max(mx, pref[n][k]);

    for(int i = 1; i <= n; i++) {
      for(int j = i+1; j <= n; j++) {
        
        for(int k = 1; k <= 26; k++) maxs[k] = maxf[k] = 0;
        for(int k = 1; k <= 26; k++) maxs[k] = max(pref[j][k] - pref[i-1][k], maxs[k-1]);
        for(int k = 26; k >= 1; k--) maxf[k] = max(pref[j][k] - pref[i-1][k], maxf[k+1]);

        for(int k = 1; k <= 26; k++) {
          int val = max(maxs[k-1], maxf[k+1]);
          int mn = min(pref[i][k], suf[j][k]);
          mx = max(mx, 2ll*mn + val);
        }

      }
    }
    cout << mx << "\n";
  } 
}
