#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define pb push_back
#define cl(x, v) memset((x), (v), sizeof(x))
#define gcd(x,y) __gcd((x),(y))

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
typedef vector<int> vi;

const ld EPS = 1e-9, PI = acos(-1.);
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 2e5+5;

ll n, m, k, p[N];
vector<ll> adj[N], adjt[N];

int dist[N];

void bfs() {
  memset(dist, 63, sizeof dist);
  queue<ll> q;
  q.push(p[k]);
  dist[p[k]] = 0;
  while(q.size()) {
    ll u = q.front(); q.pop();
    for(auto v : adj[u]) {
      if(dist[v] == INF) dist[v] = dist[u] + 1, q.push(v);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n >> m;
  ll a, b;
  for(int i = 0; i < m; i++) {
    cin >> a >> b;
    adj[b].push_back(a);
    adjt[a].push_back(b);
  }
  cin >> k;
  for(int i = 1; i <= k; i++) cin >> p[i];
  bfs();
  
  //for(int i = 1; i <= n; i++) 
  //  db(i _ dist[i]);

  ll mn = 0, mx = 0;
  ll u = 1;
  // min
  while(u != k) {
    if(dist[p[u+1]] + 1 == dist[p[u]]) mn--;
    mn++;
    u++;
  }

  u = 1;
  // max
  while(u != k) {
    int cond = 0;
    for(auto v : adjt[p[u]]) {
      if(dist[v] + 1 == dist[p[u]] and v != p[u+1]) {
        cond = 1;
        break;
      }
    }
    if(cond) mx++;
    u++;
  }

  cout << mn << " " << mx << "\n";

}
