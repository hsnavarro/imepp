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
const int N = 1e6+5;

ll t, n, k;
map<ll, ll> freq;

ll bit[N], a[N];

void add(int p, ll v) {
    for (p+=2; p<N; p+=p&-p) bit[p] += v;
}

void update(int l, int r, ll val = 1) { add(l, val), add(r+1, -val); }

ll query(int p) {
    ll r = 0;
    for (p+=2; p; p-=p&-p) r += bit[p];
    return r;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> t;
  while(t--) {
    cin >> n >> k;
    freq.clear();
    for(int i = 0; i <= 2*k+10; i++) bit[i] = 0;
    for(int i = 1; i <= n; i++) cin >> a[i];

    for(int i = 1; i <= n/2; i++) {
      ll left = a[i];
      ll right = a[n-i+1];
      freq[left + right]++;
      update(min(left, right) + 1, max(left, right) + k);
    }
    
    ll ans = INF;
    for(int i = 2; i <= 2*k; i++) {
      ll in = query(i);
      ll val = query(i) + (n/2 - in) * 2ll;
      val -= freq[i];
      ans = min(ans, val);
    }

    cout << ans << "\n";
  }
}

