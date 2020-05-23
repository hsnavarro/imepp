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
const int N = 3e3+5;

#define int long long

int n, m, area;
bool visited[N][N], blocked[N][N][2];
vector<int> xs, ys;
vector<tuple<int, int, int>> ns, ms;
 
bool isOut(int x, int y) {
  if(x == -1 or y == ys.size() or !y or x == xs.size() - 1) return true;
  return false;
}

bool isBlocked(int x, int y, int op) {
  if(x < 0 or x >= xs.size()) return false;
  if(y < 0 or y >= ys.size()) return false;
  return blocked[x][y][op];
}

bool isVisited(int x, int y) {
  if(x < 0 or x >= xs.size()) return false;
  if(y < 0 or y >= ys.size()) return false;
  return visited[x][y];
}

int bfs(int xst, int yst) {
  queue<pair<int, int>> q;
  q.push({xst, yst});
  while(q.size()) {
    int x = q.front().st;
    int y = q.front().nd;
    q.pop();
    if(isVisited(x, y)) continue;
    if(isOut(x, y)) return 0;
    
    visited[x][y] = true;
    area += (xs[x+1] - xs[x]) * (ys[y] - ys[y-1]);

    if(!isBlocked(x, y, 0)) q.push({x, y+1});
    if(!isBlocked(x, y-1, 0)) q.push({x, y-1});
    if(!isBlocked(x+1, y-1, 1)) q.push({x+1, y});
    if(!isBlocked(x, y-1, 1)) q.push({x-1, y});
  }
  return 1;
}

int32_t main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n >> m;
  xs.pb(0), ys.pb(0);
  while(n--) {
    int a, b, c;
    cin >> a >> b >> c;
    ns.pb({a, b, c});
    xs.pb(a), xs.pb(b), ys.pb(c);
  } 

  while(m--) {
    int d, e, f;
    cin >> d >> e >> f;
    ms.pb({d, e, f});
    xs.pb(d), ys.pb(e), ys.pb(f);
  }

  sort(xs.begin(), xs.end());
  sort(ys.begin(), ys.end());
  xs.resize(unique(xs.begin(), xs.end()) - xs.begin());
  ys.resize(unique(ys.begin(), ys.end()) - ys.begin());

  for(int i = 0; i < ns.size(); i++) {
    int ai, bi, ci;
    tie(ai, bi, ci) = ns[i];

    int ci_pos = lower_bound(ys.begin(), ys.end(), ci) - ys.begin();
    int pos = lower_bound(xs.begin(), xs.end(), ai) - xs.begin();

    while(pos < xs.size() and xs[pos] < bi) {
      blocked[pos][ci_pos][0] = true;
      pos++;
    }
  }

  for(int i = 0; i < ms.size(); i++) {
    int dj, ej, fj;
    tie(dj, ej, fj) = ms[i];

    int dj_pos = lower_bound(xs.begin(), xs.end(), dj) - xs.begin();
    int pos = lower_bound(ys.begin(), ys.end(), ej) - ys.begin();

    while(pos < ys.size() and ys[pos] < fj) {
      blocked[dj_pos][pos][1] = true;
      pos++;
    }
  }

  int x = lower_bound(xs.begin(), xs.end(), 0) - xs.begin();
  int y = lower_bound(ys.begin(), ys.end(), 0) - ys.begin();

  cout << (bfs(x, y) ? to_string(area) : "INF") << "\n";
}
