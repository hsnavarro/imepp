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

const int INF = 0x3f3f3f3f;
const ll MOD = 1e9+7;
const int N = 1e6+5;

ll n, k, sum_mn[N], sum_mx[N];

ll add(ll a, ll b) {
  a %= MOD, b %= MOD;
  if(a + b > MOD) return a + b - MOD;
  return a + b;
}

ll sub(ll a, ll b) {
  a %= MOD, b %= MOD;
  if(a - b < 0) return a - b + MOD;
  return a - b;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n >> k;

  for(ll i = 1; i <= n+1; i++) sum_mn[i] = sum_mn[i-1] + (i-1ll);
  for(ll i = 1; i <= n+1; i++) sum_mx[i] = sum_mx[i-1] + (n-i+1ll);

  //for(int i = 0; i <= n+1; i++) {
  //  db(i _ sum_mn[i] _ sum_mx[i]);
  //}
  
  ll ans = 0;
  for(ll i = k; i <= n+1; i++) ans = add(ans, add(sub(sum_mx[i], sum_mn[i]), 1ll));
  cout << ans << "\n";
}

