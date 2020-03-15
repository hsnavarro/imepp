#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define pb push_back

typedef long long ll;

const int N = 2e3 + 5;

int n, m, a, b, vis[2*N], ord[2*N], ordn, cnt, cmp[2*N], val[N];
vector<int> adj[2*N], adjt[2*N];

void clear() {
  for(int i = 1; i <= 2*n; i++) {
    vis[i] = ord[i] = cmp[i] = val[i] = 0;
    adj[i].clear();
    adjt[i].clear();
  }
  ordn = cnt = 0;
}

int v(int x) { return 2*x; }
int nv(int x) { return 2*x+1; }

// add a -> b
void add(int a, int b) {
  adj[a].push_back(b);
  adj[b^1].push_back(a^1);
  adjt[b].push_back(a);
  adjt[a^1].push_back(b^1);
}

// add clause (a v b)
void add_or(int a, int b){
  add(a^1, b);  
}

void dfs(int x){
  vis[x] = 1;
  for(auto v : adj[x]) if(!vis[v]) dfs(v);
  ord[ordn++] = x;
}

void dfst(int x){
  cmp[x] = cnt, vis[x] = 0;
  for(auto v : adjt[x]) if(vis[v]) dfst(v);
}

bool run2sat(){
  for(int i = 1; i <= n; i++) {
    if(!vis[v(i)]) dfs(v(i));
    if(!vis[nv(i)]) dfs(nv(i));
  }
  for(int i = ordn-1; i >= 0; i--) 
    if(vis[ord[i]]) cnt++, dfst(ord[i]);
  for(int i = 1; i <= n; i ++){
    if(cmp[v(i)] == cmp[nv(i)]) return false;
    val[i] = cmp[v(i)] > cmp[nv(i)];
  }
  return true;
}

vector<pair<int, int>> clauses;

bool test(int x) {
  clear();
  for(auto x : clauses) {
    int a = x.st > 0 ? v(abs(x.st)) : nv(abs(x.st));
    int b = x.nd > 0 ? v(abs(x.nd)) : nv(abs(x.nd));
    add_or(a, b);
  }
  if(x) add_or(v(x), v(x));
  return run2sat();
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n >> m;
  int ok = 0;
  while(m--) {
    cin >> a >> b;
    if(a < 0 and b < 0) ok = 1;
    clauses.pb({a, b});
  }
  if(!ok) return cout << "-1\n", 0;

  if(!test(0)) return cout << "0\n", 0;

  for(int i = 1; i <= n; i++) {
    if(!test(i)) return cout << "1\n", 0;
  }

  cout << 2 << "\n";
}
