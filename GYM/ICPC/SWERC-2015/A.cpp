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
const int N = 5e3+5;

int A, B, n, m;
vector<int> adj[N], adjd[N];
int cnt, reach[N], need[N], vis[N];

void dfs(int u, int node) {
  reach[node]++;
  vis[u] = cnt;
  for(auto v : adj[u]) if(vis[v] != cnt) dfs(v, node);
}

void dfsd(int u, int node) {
  need[node]++;
  vis[u] = cnt;
  for(auto v : adjd[u]) if(vis[v] != cnt) dfsd(v, node);
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> A >> B >> n >> m;
  int x, y;
  while(m--) {
    cin >> x >> y;
    adj[x].pb(y);
    adjd[y].pb(x);
  }

  int res1 = 0, res2 = 0, res3 = 0;
  for(int i = 0; i < n; i++) {
    cnt++;
    dfs(i, i);
    cnt++;
    dfsd(i, i);
  }

  for(int i = 0; i < n; i++) {
    if(n - reach[i] < A) res1++;
    if(n - reach[i] < B) res2++;
    if(need[i] > B) res3++;
  }

  cout << res1 << "\n";
  cout << res2 << "\n";
  cout << res3 << "\n";

}

