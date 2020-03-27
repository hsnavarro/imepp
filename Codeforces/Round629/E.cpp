#include <bits/stdc++.h>
using namespace std;

mt19937 rndll(chrono::steady_clock::now().time_since_epoch().count());

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

int n, q, a, b, cnt, k, par[N];
vector<int> adj[N], v;
pair<int, int> rng[N];

void dfs(int u, int p) {
  par[u] = (p != -1 ? p : u);
  rng[u] = {INF, -INF};
  for(auto v : adj[u])
    if(v != p) {
      dfs(v, u);
      rng[u].st = min(rng[u].st, rng[v].st);
      rng[u].nd = max(rng[u].nd, rng[v].nd);
    }

  if(rng[u].st == INF) cnt++, rng[u] = {cnt, cnt};
}

bool query(vector<int> &v) {
  int l = -INF, r = INF;
  for(auto x : v) l = max(l, rng[par[x]].st), r = min(r, rng[par[x]].nd);
  return l <= r;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n >> q;
  for(int i = 0; i < n-1; i++) {
    cin >> a >> b;
    adj[a].pb(b), adj[b].pb(a);
  }
  dfs(1, -1);
  while(q--) {
    cin >> k;
    v.resize(k);
    for(int i = 0; i < k; i++) cin >> v[i];
    cout << (query(v) ? "YES\n" : "NO\n");
  }
}

