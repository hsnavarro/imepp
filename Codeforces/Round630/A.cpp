#include <bits/stdc++.h>
using namespace std;

mt19937_64 llrand((int) std::chrono::steady_clock::now().time_since_epoch().count());

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

ll t, a, b, c, d, x, y, xa, ya, xb, yb;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> t;
  while(t--) {
    cin >> a >> b >> c >> d;
    cin >> x >> y >> xa >> ya >> xb >> yb;
    ll dx1 = (x - xa);
    ll dx2 = (xb - x);
    ll dy1 = (y - ya);
    ll dy2 = (yb - y);
    if((a or b) and (dx1 < 1 and dx2 < 1)) cout << "NO\n";
    else if((c or d) and (dy1 < 1 and dy2 < 1)) cout << "NO\n";
    else {
      //db("entrou aqui");
      if( x + b - a < xa or x + b - a > xb) cout << "NO\n";
      else if( y + d - c < ya or y + d - c > yb) cout << "NO\n";
      else cout << "YES\n";
    }
  }
}

