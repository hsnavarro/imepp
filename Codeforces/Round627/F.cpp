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
const int N = 2e5+5;

int n, dp[N], a[N], ans[N];
vector<int> adj[N];
int x, y;

void dfs(int u, int p) {
  dp[u] = a[u] ? 1 : -1;
  for(auto v : adj[u]) {
    if(v == p) continue;
    dfs(v, u);
    dp[u] += max(0, dp[v]);
  }
} 

void dfs2(int u, int p) {
  int a = 0, b = 0;
  if(p != -1) a = dp[p];
  b = dp[u];
  if(p != -1) dp[p] -= max(0, b);
  dp[u] += max(0, dp[p]);
  ans[u] = dp[u];
  for(auto v : adj[u]) if(v != p) dfs2(v, u);
  if(p != -1) dp[p] += max(0, b);
  dp[u] -= max(0, dp[p]);
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  for(int i = 1; i <= n; i++) cin >> a[i];
  for(int i = 0; i < n-1; i++) {
    cin >> x >> y;
    adj[x].pb(y);
    adj[y].pb(x);
  }
  dfs(1, -1);
  dfs2(1, -1);
  for(int i = 1; i <= n; i++) cout << ans[i] << " ";
  cout << "\n";
}

