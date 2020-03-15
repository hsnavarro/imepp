#include <bits/stdc++.h>
using namespace std;

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
const int N = 1e5+5;

vector<int> adj[N];
int n, a, b, par[N], forb[N], mx1, node_mx1, mx2, node_mx2;

void dfs1(int u, int p, int h) {
  if(h > mx1) mx1 = h, node_mx1 = u;
  for(auto v : adj[u]) {
    if(v != p and !forb[v]) dfs1(v, u, h+1);
  }
}

void dfs2(int u, int p, int h) {
  if(h > mx2) mx2 = h, node_mx2 = u;
  for(auto v : adj[u]) {
    if(v != p and !forb[v]) dfs2(v, u, h+1);
  }
}

void find_path(int u, int p) {
  if(p != -1) par[u] = p;
  for(auto v : adj[u]) {
    if(v != p and !forb[v]) find_path(v, u);
  }
}

void solve() {
  int ans = 1, cnt = 0;
  for(auto v : adj[ans]) if(!forb[v]) cnt++;
  while(cnt) {
    mx1 = 0, mx2 = 0, cnt = 0;
    dfs1(ans, -1, 0);
    dfs2(node_mx1, -1, 0);
    
    int res;
    cout << "? " << node_mx1 << " " << node_mx2 << endl;
    cin >> res;
    ans = res;
    find_path(ans, -1);
    int u = node_mx1;
    while(u != ans) forb[u] = 1, u = par[u];
    u = node_mx2;
    while(u != ans) forb[u] = 1, u = par[u];

    for(auto v : adj[ans]) if(!forb[v]) cnt++;
  }
  cout << "! " << ans << "\n";
}


int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  for(int i = 0; i < n-1; i++) {
    cin >> a >> b;
    adj[a].pb(b);
    adj[b].pb(a);
  }
  solve();
}
