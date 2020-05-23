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
const int N = 2e5+5;

ll n, sz[N], h[N], ans;
vector<int> adj[N];
int a, b;

void dfs(int u, int p, int ht) {
  h[u] = ht;
  sz[u] = 1;
  for(auto v : adj[u]) {
    if(v != p) {
      dfs(v, u, ht + 1);
      sz[u] += sz[v];
    }
  }
}

void transfer(int u, int p, ll val) {
  ans = (ans + (val%MOD)) % MOD;
  for(auto v : adj[u]) {
    if(v != p) transfer(v, u, val + n - 2*sz[v]);
  }
}

ll mult(ll a, ll b) { return (a*b) % MOD; }

ll inv(ll b) {
  ll ans = 1;
  ll e = MOD - 2;
  while(e) {
    if(e & 1) ans = (ans*b) % MOD;
    b = (b*b) % MOD;
    e = e/2;
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  for(int i = 0; i < n-1; i++) {
    cin >> a >> b;
    adj[a].pb(b);
    adj[b].pb(a);
  }
  dfs(1, -1, 0);
  ll val = 0;
  for(int i = 1; i <= n; i++) val += h[i];
  transfer(1, -1, val);
  cout << mult(ans, inv(mult(n, (n+1)))) << "\n";

  /*
  const int A = (1e4 + 5);
  for(int i = 0; i < A; i++) {
    for(int j = 0; j < A; j++) if(mult(i, inv(j)) == 300000003) {
      db(i _ j);
      return 0;
    }
  }
  */
}

