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
const int N = 5e5+5;

ll n, a[N], sm, mx1, mx2;
string s;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  for(int i = 0; i < n; i++) cin >> a[i];
  cin >> s;
  for(int i = 0; i < n; i++) if(s[i] == 'B') sm += a[i];
  ll pref = 0, suf = 0;
  for(int i = 0; i < n; i++) {
    if(s[i] == 'A') pref += a[i];
    else pref -= a[i];
    mx1 = max(mx1, pref);
  }

  for(int i = n-1; i >= 0; i--) {
    if(s[i] == 'A') suf += a[i];
    else suf -= a[i];
    mx2 = max(mx2, suf);
  }
  cout << sm + max(mx1, mx2) << "\n";
}

