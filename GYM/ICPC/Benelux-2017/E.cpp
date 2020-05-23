#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define pb push_back

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;

#define db(x) cerr << #x << " == " << 
#define _ << ", " << 

const int N = 250 + 5;

int n, r, b, cnt, vis[2*N], match[2*N], ans;
ld x[2*N], y[2*N];
vector<int> adj[2*N];

bool find(int x) {
  if(vis[x] == cnt) return false;
  vis[x] = cnt;
  for(auto u : adj[x]) if(!match[u] or find(match[u])) return match[u] = x;
  return false;
}

// MIS : V - MATCH

ld dist(int i, int j) {
  ld dx = x[i] - x[j];
  ld dy = y[i] - y[j];
  return sqrt(dx*dx + dy*dy);
}

void build(ld x) {
  for(int i = 0; i <= (r+b); i++) adj[i].clear();
  
  for(int i = 1; i <= b; i++) {
    for(int j = b+1; j <= b+r; j++) if(dist(i, j) < x) adj[i].push_back(j);
  }
}

bool test(ld x) {
  build(x);
  for(int i = 0; i <= (r+b); i++) random_shuffle(adj[i].begin(), adj[i].end());
  cnt = 0, ans = 0;
  for(int i = 0; i <= (r+b); i++) vis[i] = match[i] = 0;
  for(int i = 1; i <= (r+b); i++) ++cnt, ans += find(i);
  return (r+b) - ans >= n;
}

ld bin(ld l = 0, ld r = 1e12) {
  ld mid;
  while(r - l > (1e-7)) {
    mid = (l+r)/2;
    if(test(mid)) l = mid;
    else r = mid;
  }
  return l;
}


int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n >> b >> r;
  for(int i = 1; i <= b; i++) cin >> x[i] >> y[i];
  for(int i = b+1; i <= b+r; i++) cin >> x[i] >> y[i];
  cout << fixed << setprecision(10) << bin() << "\n";
}
