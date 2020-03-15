#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define st first
#define nd second

typedef pair<int, int> pii;
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

int n, m, a, b, x, y;
vector<int> s1, s2;
ll resp;

const int N = 2e5 + 5;

int t, par[N], sz[N];
vector<pair<int, int>> edg;
set<int> s;

int find(int a) { return a == par[a] ? a : par[a] = find(par[a]); }

void unite(int a, int b){
    if(find(a) == find(b)) return;
    a = find(a), b = find(b);
    if(sz[a] < sz[b]) swap(a, b);
    sz[a] += sz[b], par[b] = a;
}

int main(){
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> t;
  while(t--){
    cin >> n >> m >> a >> b;
    edg.clear(), s1.clear(), s2.clear(), resp = 0ll;
    while(m--){
      cin >> x >> y;
      edg.pb({x, y});
    }

    // a
    for(int i = 1; i <= n; i++) par[i] = i, sz[i] = 1;
    for(auto p : edg){
      if(p.st != a and p.nd != a) unite(p.st, p.nd);
    }
    s.clear();
    for(int i = 1; i <= n; i++) if(i != a and find(i) != find(b)) s.insert(find(i));
    for(auto x : s) s1.pb(sz[x]);

    // b
    for(int i = 1; i <= n; i++) par[i] = i, sz[i] = 1;
    for(auto p : edg){
      if(p.st != b and p.nd != b) unite(p.st, p.nd);
    }
    s.clear();
    for(int i = 1; i <= n; i++) if(i != b and find(i) != find(a)) s.insert(find(i));
    for(auto x : s) s2.pb(sz[x]);

    ll sum1 = 0ll, sum2 = 0ll;

    for(auto x : s1) sum1 += 1ll*x;
    for(auto x : s2) sum2 += 1ll*x;

    cout << 1ll*sum1*sum2 << "\n";
  }
}
