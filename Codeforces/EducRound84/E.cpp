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

const int INF = 0x3f3f3f3f, MOD = 998244353;
const int N = 2e5+5;

int n;
ll ans = 10, p[N];
vector<ll> res;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  p[0] = 1;
  for(ll i = 1; i < N; i++) p[i] = (10ll*p[i-1]) % MOD;
  
  res.pb(ans);
  for(int i = 2; i <= n; i++) {
    ans = (ans*10ll) % MOD;
    ans = (ans + ((81*p[i-2]) % MOD)) % MOD;
    if(i == 2) ans--;
    res.pb(ans);
  }
  reverse(res.begin(), res.end());
  for(auto x : res) cout << x << " ";
  cout << "\n";
}
