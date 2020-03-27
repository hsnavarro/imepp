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
const int N = 2e5+5;

int t, n, a[N], c[N];

bool ok() {
  return (a[1] == a[2] or c[1] != c[2]) and 
    (a[n] == a[n-1] or c[n] != c[n-1]) and 
    (a[1] == a[n] or c[1] != c[n]);
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> t;
  while(t--) {
    cin >> n;
    int cnt = 0, ans = 0;
    for(int i = 1; i <= n; i++) cin >> a[i], cnt += (a[i] == a[1]);
    if(cnt == n) {
      ans = 1;
      for(int i = 1; i <= n; i++) c[i] = 1;
    } else {
      ans = 2;
      c[1] = 1;
      for(int i = 2; i <= n; i++) {
        c[i] = 1;
        if(a[i] != a[i-1]) while(c[i-1] == c[i]) c[i]++;
      }

      if(!ok()) {
        c[1] = 2;
        for(int i = 2; i <= n; i++) {
          c[i] = 1;
          if(a[i] != a[i-1]) while(c[i-1] == c[i]) c[i]++;
        }
      }

      if(!ok()) c[n] = 3, ans++;
    }
    cout << ans << "\n";
    for(int i = 1; i <= n; i++) cout << c[i] << " ";
    cout << "\n";
  }
}
