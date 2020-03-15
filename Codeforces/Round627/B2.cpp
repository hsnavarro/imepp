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
const int N = 5e3+5;

int t, n, a[N], last[N];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> t;
  while(t--) {
    cin >> n;
    for(int i = 0; i < n; i++) {
      cin >> a[i];
      last[i+1] = -1;
    }
    for(int i = 0; i < n; i++) last[a[i]] = i;
    int cond = 0;
    for(int i = 0; i < n; i++) {
      for(int j = i+1; j < n; j++) {
        if(last[a[i]] > j) {
          cond = 1;
          break;
        }
      }
    }
    cout << (cond ? "YES\n" : "NO\n");
  }
}

