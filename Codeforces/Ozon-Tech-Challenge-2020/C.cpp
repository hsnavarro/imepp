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

ll n, m;
vector<ll> a; 

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n >> m;
  a.resize(n);
  for(int i = 0; i < n; i++) cin >> a[i];
  if(n > m) cout << 0 << "\n";
  else {
    ll ans = 1%m;
    for(int i = 0; i < n; i++)
      for(int j = i+1; j < n; j++) ans = (ans*abs(a[j] - a[i])) % m;
    cout << ans << "\n";
  }
}
