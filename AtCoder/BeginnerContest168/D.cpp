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
const int N = 1e5+5;

vector<int> adj[N];
int dist[N];
int resp[N];
int n, m, a, b;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n >> m;
  while(m--) {
    cin >> a >> b;
    adj[a].pb(b);
    adj[b].pb(a);
  }

  queue<int> q;
  memset(dist, 63, sizeof dist);
  dist[1] = 0;
  q.push(1);
  while(q.size()) {
    int u = q.front();
    q.pop();

    for(auto v : adj[u]) 
      if(dist[v] == INF) {
        dist[v] = dist[u] + 1;
        q.push(v);
      }
  
  }

  for(int i = 2; i <= n; i++) {
    for(auto v : adj[i]) if(dist[v] + 1 == dist[i]) resp[i] = v;
  }

  int ok = 1;
  for(int i = 2; i <= n; i++) if(!resp[i]) ok = 0;

  if(!ok) cout << "No\n";
  else {
    cout << "Yes\n";
    for(int i = 2; i <= n; i++) cout << resp[i] << "\n";
  }
} 

