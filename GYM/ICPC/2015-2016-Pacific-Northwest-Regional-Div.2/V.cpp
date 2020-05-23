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
const int N = 1e3+5;

struct circle {
  ll x, y, r;
};

bool isCW[N], visited[N];

int n;
pll w[N];
circle c[N];

bool isImpossible = false;

ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }

pll mult(pll a, pll b) {
  ll num = a.st * b.st;
  ll dem = a.nd * b.nd;
  ll mdc = gcd(num, dem);

  return { num/mdc, dem/mdc };
}

bool reach(int a, int b) {
  ll dx = c[a].x - c[b].x;
  ll dy = c[a].y - c[b].y;
  ll sr = c[a].r + c[b].r;

  return dx*dx + dy*dy <= sr*sr;
}

void dfs(int x) {

  set<ll> rs;
  set<pll> ws;
  set<bool> ori;
  vector<int> callDfs;

  for(int i = 1; i <= n; i++) {
    if(i == x) continue;

    if(reach(x, i)) {
      if(visited[i]) rs.insert(c[i].r), ori.insert(isCW[i]), ws.insert(w[i]);
      else callDfs.pb(i);
    }
  }

  if(rs.size() > 1 or ws.size() > 1 or ori.size() > 1) {
    isImpossible = true;
    return;
  }

  for(auto v : callDfs) {
    visited[v] = true;
    isCW[v] = isCW[x]^1;
    w[v] = mult(w[x], {c[x].r, c[v].r});
    dfs(v);

    if(isImpossible) return;
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  for(int i = 1; i <= n; i++) cin >> c[i].x >> c[i].y >> c[i].r;
  visited[1] = true;
  w[1] = {1ll, 1ll};
  isCW[1] = true;

  dfs(1);

  if(isImpossible) cout << "The input gear cannot move.\n";
  else if(!visited[n]) cout << "The input gear is not connected to the output gear.\n";
  else {
    if(isCW[n]) cout << w[n].st << ":" << w[n].nd << "\n";
    else cout << -w[n].st << ":" << w[n].nd << "\n";
  }

}

