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

int t, n, p[N], c[N], dist[N], ans;
// para cada cor, para cada ciclo
vector<int> visited;
map<int, vector<int>> process;

void dfs(int u) {
  visited.pb(u);
  if(!dist[p[u]]) {
    dist[p[u]] = dist[u] + 1;
    dfs(p[u]);
  }
}

void pro() {
  ans = min(ans, (int) visited.size());
  for(auto x : visited) process[c[x]].clear();
  for(auto x : visited) process[c[x]].pb(x);

  set<int> aux;
  for(auto v : process) {
    aux.clear();
    for(int i = 0; i < v.nd.size(); i++) {
      
      if(i == v.nd.size() - 1) aux.insert(dist[v.nd[0]] + visited.size() - dist[v.nd[i]]);
      else aux.insert(dist[v.nd[i+1]] - dist[v.nd[i]]);
    }
    if(aux.size() == 1) ans = min(ans, *(aux.begin()));
  }
}



int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> t;
  int cnt = 0;
  while(cin >> n) {
    ++cnt;
    
    //cin >> n;
    ans = INF;
    for(int i = 1; i <= n; i++) dist[i] = 0;
    for(int i = 1; i <= n; i++) cin >> p[i];
    for(int i = 1; i <= n; i++) cin >> c[i];

    if(cnt == 19) {
      cout << n << "\n";
      for(int i = 1; i <= n; i++) cout << p[i] << " ";
      cout << "\n";
      for(int i = 1; i <= n; i++) cout << c[i] << " ";
      cout << "\n";
    }

    for(int i = 1; i <= n; i++) if(!dist[i]) visited.clear(), dist[i] = 1, dfs(i), pro();
    cout << ans << "\n";
  }
}
