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
const int N = 2e3+5;

int n, h, l, r;
int dp[N][N], a[N];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n >> h >> l >> r;
  for(int i = 0; i < n; i++) cin >> a[i];
  for(int i = 0; i <= n; i++) 
    for(int j = 0; j < h; j++) dp[i][j] = -1;

  dp[0][0] = 0;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < h; j++) {
      if(dp[i][j] == -1) continue;
      int op1 = (j + a[i]) % h;
      int op2 = (j + a[i] - 1) % h;
      dp[i+1][op1] = max(dp[i+1][op1], dp[i][j] + (op1 >= l and op1 <= r));
      dp[i+1][op2] = max(dp[i+1][op2], dp[i][j] + (op2 >= l and op2 <= r));
    }
  }
  int mx = 0;
  for(int j = 0; j < h; j++) mx = max(mx, dp[n][j]);
  cout << mx << "\n";
}

