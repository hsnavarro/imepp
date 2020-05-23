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

int t, n, k;

// 1 2 .. x x+1 x+2 .... 2*x
//
// 1 2 3 4
//
// k * (x - 1) + n - k * x == t
// k == n/x
//
// n/x * (x - 1) + n - n/x * x == t
//
// n - n/x == t
// 10 - 10/3
// 10 - 3
//
// n*x - n == t*x
// n = t*x/x-1



int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> t;
  while(t--) {
    cin >> n >> k;
    //cout << k*n/(n-1) << "\n";
    // x - x/n == k
    
    ll l = 0, r = (1e18);
    ll mid;
    while(l != r) {
      mid = (l + r)/2;
      if(mid - mid/n < k) l = mid+1;
      else r = mid;
    }

    cout << l << "\n";
  }
}

