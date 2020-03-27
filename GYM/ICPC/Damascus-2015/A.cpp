#include <bits/stdc++.h>
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

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
const int N = 20+5;

int t, n;
ld a[N][N], dp[1 << 21];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> t;
  for(int k = 1; k <= t; k++) {
    cin >> n;
    for(int i = 0; i < n; i++)
      for(int j = 0; j < n; j++) cin >> a[i][j];

    for(int i = 0; i < (1 << n); i++) dp[i] = 0;
    dp[0] = 1.0;
    for(int i = 1; i < (1 << n); i++) {
      ld sz = 0.0;
      for(int j = 0; j < n; j++) if(!(i & (1 << j))) sz += 1.0;
      for(int k = 0; k < n; k++) if(i & (1 << k)) {
        ld sum = 0.0;
        for(int p = 0; p < n; p++) if(!(i & (1 << p))) sum += a[p][k];
        dp[i] += 2.0 * (1/(sz*(sz+1))) * sum * dp[i - (1 << k)];
      }
    }

    cout << "Case " << k << ": ";
    for(int i = 0; i < n; i++) cout << fixed << setprecision(6) << dp[(1 << n) - 1 - (1 << i)] << " \n"[i == n-1];
  }
}

