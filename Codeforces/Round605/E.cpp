#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second

typedef pair<int, int> pii;
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

const int N = 2e5 + 5;

int n, a[N], ans[N], dist[N];
vector<int> adj[N], par, impar;

void bfs(int op1){
  memset(dist, INF, sizeof dist);
  queue<int> q;
  if(op1) for(auto x : impar) dist[x] = 0, q.push(x);
  else for(auto x : par) dist[x] = 0, q.push(x);

  while(q.size()){
    int u = q.front();
    q.pop();
    for(auto x : adj[u]) 
      if(dist[x] == INF) dist[x] = dist[u] + 1, q.push(x);
  }
}

int main(){
  ios_base::sync_with_stdio(0), cin.tie(0);
  memset(ans, INF, sizeof ans);
  cin >> n;
  for(int i = 1; i <= n; i++) {
    cin >> a[i];
    if(a[i] & 1) impar.push_back(i);
    else par.push_back(i);
    if(i - a[i] >= 1) adj[i - a[i]].push_back(i);
    if(i + a[i] <= n) adj[i + a[i]].push_back(i);
  }

  bfs(0);
  for(int i = 1; i <= n; i++) if(a[i] & 1) ans[i] = min(ans[i], dist[i]);
  bfs(1);
  for(int i = 1; i <= n; i++) if(!(a[i] & 1)) ans[i] = min(ans[i], dist[i]);
  for(int i = 1; i <= n; i++) cout << (ans[i] == INF ? -1 : ans[i]) << " ";
  cout << "\n";









}
