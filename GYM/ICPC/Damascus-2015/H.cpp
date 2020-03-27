#include <bits/stdc++.h>
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

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

ll c1, n1, c2, n2, n;

void euclid(ll a, ll b, ll &x, ll &y, ll &d) {
  if (b) euclid(b, a%b, y, x, d), y -= x*(a/b);
  else x = 1, y = 0, d = a;
}

bool find_any_solution(ll a, ll b, ll c, ll &x0, ll &y0, ll &g) {
  euclid(abs(a), abs(b), x0, y0, g);

  if (c % g) {
    return false;
  }

  x0 *= c / g;
  y0 *= c / g;
  if (a < 0) x0 = -x0;
  if (b < 0) y0 = -y0;
  return true;
}

void shift_solution (ll & x, ll & y, ll a, ll b, ll cnt) {
  x += cnt * b;
  y -= cnt * a;
}

pair<ll, ll> find_solution (ll a, ll b, ll c) {
  ll x, y, g;
  if (! find_any_solution (a, b, c, x, y, g)) return {-1, -1};
  a /= g;  b /= g;
  shift_solution (x, y, a, b, -x / b);
  if (x < 0) shift_solution (x, y, a, b, 1);
  if(y < 0) return {-1, -1};
  return {x, y};
}

int32_t main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  while(cin >> n and n) {
    int sp = 0;
    cin >> c1 >> n1;
    cin >> c2 >> n2;
    if(c2*n1 > c1*n2) swap(n1, n2), sp = 1;
    pii ans = find_solution(n1, n2, n);
    if(ans.st == -1) cout << "failed\n";
    else {
      if(sp) swap(ans.st, ans.nd);
      cout << ans.st << " " << ans.nd << "\n";
    }

  }
}

