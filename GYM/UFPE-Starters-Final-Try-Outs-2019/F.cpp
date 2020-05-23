#include <bits/stdc++.h>
using namespace std;

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

ll n, fat[25];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n;  
  fat[0] = 1;
  for(int i = 1; i < 25; i++) fat[i] = (1ll*i*fat[i-1]) % MOD;

  ll ans = 0;
  for(int i = 0; i < (1 << n); i++) {
    int set = __builtin_popcount(i);
    if((n - set) & 1) ans = (ans - fat[set] + MOD) % MOD;
    else ans = (ans + fat[set]) % MOD;
  }
  cout << ans << "\n";
}

