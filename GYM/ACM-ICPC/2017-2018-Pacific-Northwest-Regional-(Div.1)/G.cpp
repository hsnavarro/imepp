#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define pb push_back

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;

const int N = 1000 + 5;

int n, m, k, s, t, vis[N], cnt;
vector<piii> adj[N];
vector<int> events;
int a, b, c, d;

void dfs(int u, int esc) {
  vis[u] = cnt;
  for(auto v : adj[u]) 
    if(vis[v.st] != cnt and esc >= v.nd.st and esc <= v.nd.nd) 
      dfs(v.st, esc);
}


int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n >> m >> k;
  cin >> s >> t;
  while(m--) {
    cin >> a >> b >> c >> d;
    adj[a].pb({b, {c, d}});
    events.pb(c);
    events.pb(d+1);
  }

  sort(events.begin(), events.end());
  events.resize(unique(events.begin(), events.end()) - events.begin());
  events.push_back(k+1);

  int sum = 0;
  for(int i = 0; i+1 < events.size(); i++) {
    cnt++;
    dfs(s, events[i]);
    if(vis[t] == cnt) sum += events[i+1] - events[i]; 
  }
  cout << sum << "\n";
}
