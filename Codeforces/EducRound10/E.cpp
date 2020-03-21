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
const int N = 3e5+5;

int n, m, a, b, x, s, t;
int ok[N];
vector<pair<int, int>> adj[N];
vector<pair<pii, int>> edgs;

set<int> adjt[N];
map<pair<int, int>, int> one;

vector<int> st;
int num[N], low[N], vis[N], cnt, cmp[N], sccn=1;

void dfs(int u, int p) {
  num[u] = low[u] = ++cnt;
  int ch = 0;
  st.push_back(u), vis[u] = 1;

  for(auto x : adj[u]) {
    int v = x.st;
    if (!num[v]) dfs(v, u);
    if (vis[v] and v != p) low[u] = min(low[u], low[v]);
  }

  if (low[u] == num[u]) while(1) {
      int v = st.back(); st.pop_back();
      cmp[v] = sccn, vis[v] = 0;
      if (v == u) { sccn++; break; }
  }
}

void tarjan(int n) { for(int i=1; i<=n; ++i) if (!num[i]) dfs(i, -1); }

void dfs(int u) {
  vis[u] = 1;
  for(auto x : adjt[u]) {
    int v = x;
    if(vis[v]) continue;
    int w = 0;
    if(one[{u, x}]) w = 1;
    ok[v] = ok[u] | ok[v] | w;
    dfs(v);
  }
}



int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n >> m;
  while(m--) {
    cin >> a >> b >> x;
    edgs.pb({{a, b}, x});
    adj[a].pb({b, x});
    adj[b].pb({a, x});
  }
  cin >> s >> t;
  tarjan(n);
  for(int i = 1; i <= n; i++) db(i _ cmp[i]);
  for(auto x : edgs) {
    int a = x.st.st;
    int b = x.st.nd;
    int c = x.nd;
    if(cmp[a] == cmp[b]) {
      if(c) ok[cmp[a]] = 1;
      continue;
    }

    adjt[cmp[a]].insert(cmp[b]);
    adjt[cmp[b]].insert(cmp[a]);
    if(c) {
      one[{cmp[a], cmp[b]}] = 1;
      one[{cmp[b], cmp[a]}] = 1;
    }
  }
  memset(vis, 0, sizeof vis);
  dfs(cmp[s]);
  cout << (ok[cmp[t]] ? "YES\n" : "NO\n");
}

