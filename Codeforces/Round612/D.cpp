#include <bits/stdc++.h>
using namespace std;
 
#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define cl(x, v) memset((x), (v), sizeof(x))
 
#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define _ << ", " <<
 
typedef long long ll;
typedef long double ld;
 
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
 
const ld EPS = 1e-9, PI = acos(-1.);
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int N = 2e3+5;

int n, root, p[N], c[N], a[N], mx;
vector<int> adj[N];

int take_max(int u, int p){
  int mx = a[u];
  for(auto v : adj[u]) if(v != p) mx = max(mx, take_max(v, u));
  return mx;
}

void fix(int u, int p, int x){
  if(a[u] >= x) a[u]++;
  for(auto v : adj[u]) if(v != p) fix(v, u, x);
}

void sum(int u, int p, int s){
  a[u] += s;
  for(auto v : adj[u]) if(v != p) sum(v, u, s);
}

void dfs(int u = root, int p = -1) {
  int mx = 0;
  for(auto v : adj[u]) {
    if(v != p) {
        dfs(v, u);
        sum(v, u, mx);
        mx = max(mx, take_max(v, u));
    }
  }
  if(c[u] > mx) { cout << "NO\n"; exit(0);} 
  else {
    a[u] = c[u] + 1;
    for(auto v : adj[u]) if(v != p) fix(v, u, a[u]);
  }
}

int main(){
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  for(int i = 1; i <= n; i++) {
    cin >> p[i] >> c[i];
    if(!p[i]) root = i;
    if(p[i]) adj[p[i]].pb(i);
  }
  dfs();
  cout << "YES\n";
  for(int i = 1; i <= n; i++) cout << a[i] << " ";
  cout << "\n";
}
