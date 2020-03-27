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
const int N = 2e4+5;

ll fexp(ll b) {
  ll ans = 1, e = MOD - 2;
  while(e) {
    if(e & 1ll) ans = (ans*b) % MOD;
    b = (b*b) % MOD, e = e/2;
  }
  return ans;
}

ll mul(ll a, ll b) { return (a*b) % MOD; }

ll fat[N], n, m;
int t;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  fat[0] = 1;
  for(ll i = 1; i < N; i++) fat[i] = (i*fat[i-1]) % MOD;
  cin >> t;
  while(t--) {
    cin >> n >> m;
    cout << mul(fat[n+m], mul(fexp(fat[n]), fexp(fat[m]))) << "\n";
  }
}

