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

ll ha, hb, a, b;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> ha >> hb;
  cin >> a >> b;
  ha += 8*a;
  if(ha >= hb) return cout << 0 << "\n", 0;
  ha -= 12*b;
  ha += 12*a;
  if(a <= b and ha < hb) return cout << -1 << "\n", 0;
  if(ha >= hb) return cout << 1 << "\n", 0;
  int cnt = 1;
  while(ha < hb) {
    ha += 12*(a - b);
    cnt++;
  }
  cout << cnt << "\n";
}

