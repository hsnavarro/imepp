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

const ld EPS = 1e-9;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e6+5;

int n;
ld W;

string s;
ld p;
ll val;
ll lastVal = 0.0;
ld acum = 1.0;
ld sum;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n >> W;
  ld mx = -1.0;
  for(int i = 1; i <= n; i++) {
    cin >> s >> p >> val;

    // wrong answer
    sum += acum * (1.0 - p) * log(1 + lastVal/W);

    // right answer
    acum = acum * p;

    // quit
    sum += acum * log(1 + val/W);
    mx = max(mx, sum);
    sum -= acum * log(1 + val/W);

    if(s == "safe") lastVal = val;
  }

  cout << fixed << setprecision(2) << "$" << (exp(mx) - 1) * W << "\n";
}

