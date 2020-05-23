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

int t, n, a[N], b[N];
int c[2];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> t;
  while(t--) {
    cin >> n;
    int cond = 1;
    for(int i = 0; i < n; i++) {
      cin >> a[i];
      if(a[i] < 0) c[0]++;
      if(a[i] > 0) c[1]++;
    }
    for(int i = 0; i < n; i++) cin >> b[i];
    
    for(int i = n-1; i >= 0; i--) {
      if(a[i] < 0) c[0]--;
      if(a[i] > 0) c[1]--;
      
      if(a[i] < b[i] and !c[1]) cond = 0;
      if(a[i] > b[i] and !c[0]) cond = 0;
    }

    cout << (cond ? "YES\n" : "NO\n");
  }
}
