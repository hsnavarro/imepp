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

int t;
ll n, k;
vector<ll> p;

bool check(ll test) {
  int groups = 1;
  ll cnt = 0, mx = -1;
  for(auto x : p) {
    if(x > test) return false;
    cnt++;
    mx = max(mx, x);
    if(cnt*mx > test) cnt = 1, mx = x, groups++;
  }
  return groups <= k;
}

ll bin(ll l = 0, ll r = ll(1e18)) {
  ll mid;
  while(l != r) {
    mid = (l+r)/2;
    if(!check(mid)) l = mid + 1;
    else r = mid;
  }
  return l;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> t;
  while(t--) {
    cin >> n >> k;
    p.resize(n);
    for(int i = 0; i < n; i++) cin >> p[i];
    cout << bin() << "\n";
  }
}

