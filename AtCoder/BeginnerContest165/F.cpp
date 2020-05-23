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
const int N = 2e5+5;

int n, ans[N], a[N];
vector<int> dp;
vector<int> adj[N];

void dfs(int u, int p, vector<int> &dp) {
 int l = lower_bound(dp.begin(), dp.end(), a[u]) - dp.begin();
 int cond1 = 0, cond2 = 0, place;

 if(l == dp.size()) cond1 = 1, dp.push_back(a[u]);
 else cond2 = 1, place = dp[l], dp[l] = a[u];

  ans[u] = dp.size();

 for(auto v : adj[u]) if(v != p) dfs(v, u, dp);

  if(cond1) dp.pop_back();
  if(cond2) dp[l] = place;

}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  for(int i = 1; i <= n; i++) cin >> a[i];
  
  int u, v;
  for(int i = 0; i < n-1; i++) {
    cin >> u >> v;
    adj[u].pb(v);
    adj[v].pb(u);
  }
  dfs(1, -1, dp);
  for(int i = 1; i <= n; i++) cout << ans[i] << "\n";
}
