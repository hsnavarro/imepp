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
const ld pi = acos(-1.0);

ld a, b, h, m;

ld dist(ld xa, ld ya, ld xb, ld yb) {
  ld dx = xa - xb;
  ld dy = ya - yb;
  return sqrt(dx * dx + dy * dy);
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> a >> b >> h >> m;

  ld theta_h = -(pi/6) * (h + m/60);
  ld theta_m = -(pi/30) * (m + 60*h);

  cout << fixed << setprecision(12) << dist(a * sin(theta_h), a * cos(theta_h), b * sin(theta_m), b * cos(theta_m)) << "\n";
}

