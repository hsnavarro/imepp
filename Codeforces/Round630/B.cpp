#include <bits/stdc++.h>
using namespace std;

mt19937_64 llrand((int) std::chrono::steady_clock::now().time_since_epoch().count());

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

int t, n, a[N], c[N];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> t;
  while(t--) {
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i], c[i] = 0;

    int cnt = 0;
    for(int i = 2; i <= 1000; i++) {
      int cond = 0;
      for(int j = 0; j < n; j++) {
          if(!c[j] and a[j] % i == 0) cond = 1;
      }
      if(cond) {
        cnt++;
        for(int j = 0; j < n; j++) if(!c[j] and a[j] % i == 0) c[j] = cnt;
      }
    }

    cout << cnt << "\n";
    for(int i = 0; i < n; i++) cout << c[i] << " ";
    cout << "\n";
  }
}

