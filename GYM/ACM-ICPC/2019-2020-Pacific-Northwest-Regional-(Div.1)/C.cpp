#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define pb push_back

typedef pair<int, int> pii;
typedef long long ll;

const int INF = 0x3f3f3f3f;
const int N = 1e5 + 5;

int n, m, a, b, dist[N];
vector<int> adj[N];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n >> m;
  while(m--) {
    cin >> a >> b;
    adj[a].pb(b);
    adj[b].pb(a);
  }
  memset(dist, 63, sizeof dist);
  queue<int> q;
  q.push(1);
  dist[1] = 0;
  while(q.size()) {
    int x = q.front(); q.pop();
    if(x == n) {
      cout << dist[n] - 1 << "\n";
      return 0;
    }
    for(auto v : adj[x]) 
      if(dist[v] == INF) dist[v] = dist[x] + 1, q.push(v);
  }
}
