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

// dp[conj] += 2/(sz*(sz+1)) * sum p[k][j] , k in conj * dp[conj + j];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> t;
  for(int cs = 1; cs <= t; cs++) {
    cin >> n;
    for(int i = 0; i < n; i++) 
      for(int j = 0; j < n; j++) cin >> a[i][j];

    for(int i = 0; i < (1 << n); i++) dp[i] = 0;
    dp[(1 << n) - 1] = 1;

    for(int i = (1 << n) - 2; i >= 1; i--) {
      ld sz = ld(__builtin_popcount(i));
      for(int j = 0; j < n; j++) if(!(i & (1 << j))) {
        ld sum = 0.0;
        for(int k = 0; k < n; k++) if(i & (1 << k)) sum += a[k][j];
        dp[i] += 2.0/(sz*(sz+1)) * sum * dp[i + (1 << j)];
      }
    }

    cout << "Case " << cs << ": ";
    for(int i = 0; i < n; i++) cout << fixed << setprecision(6) << dp[1 << i] << " \n"[i == n-1];
  }
}

