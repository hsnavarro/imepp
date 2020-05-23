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
const int N = 1e5+5;

int t, n;
vector<ll> a;

int signal(ll b) {
  if(b < 0) return 1;
  return 0;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> t;
  while(t--) {
    cin >> n;
    a.resize(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    if(n == 1) { cout << a[0] << "\n"; continue; }

    ll sum1 = 0, mx1 = 0;

    for(int i = 0; i < n; i++) {
      if(i and signal(a[i]) != signal(a[i-1])) sum1 += mx1, mx1 = 0;
      if(mx1 == 0) mx1 = a[i];
      else mx1 = max(mx1, a[i]);
    }
    if(mx1 != 0) sum1 += mx1;

    cout << sum1 << "\n";
  }
}

