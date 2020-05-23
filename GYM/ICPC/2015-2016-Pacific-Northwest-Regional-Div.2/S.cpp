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
const int N = 2e6+5;

#define int long long

int dp[N];
vector<pair<int, int>> wav[N];
int n, t, fun, wt;

int32_t main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  while(n--) {
    cin >> t >> fun >> wt;
    wav[t].pb({fun, wt});
  }

  int mx = 0;
  for(int i = 0; i < N; i++) {
    for(auto x : wav[i]) {
      int nt = i + x.nd;
      int f = x.st;
      dp[nt] = max(dp[nt], dp[i] + f);
    }
    dp[i+1] = max(dp[i+1], dp[i]);
    mx = max(mx, dp[i]);
  }

  cout << mx << "\n";
}

