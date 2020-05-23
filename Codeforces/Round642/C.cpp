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
const int N = 5e5+5;

ll sum[N], t, n;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  sum[1] = 0;
  ll s = 8;
  ll mult = 1;

  for(int i = 3; i < N; i += 2) {
    sum[i] = sum[i-2] + s*mult;
    s += 8;
    mult++;
  }

  cin >> t;
  while(t--) {
    cin >> n;
    cout << sum[n] << "\n";
  }

}

