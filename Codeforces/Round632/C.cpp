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
const int N = 2e5+5;

ll sum[N];
map<ll, ll> mp;
ll n, ans, mx;
ll a[N];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  for(int i = 1; i <= n; i++) cin >> a[i];
 
  mp[0] = 0;
  mx = 0;
  for(int i = 1; i <= n; i++) {
    sum[i] = a[i] + sum[i-1];
    if(!mp.count(sum[i])) ans += i - mx;
    else {
      ans += min((i - (mp[sum[i]] + 2) + 1), i - mx);
      mx = max(mx, mp[sum[i]]+1);
    }
    mp[sum[i]] = i;
    //db(i _ ans);
  }

  cout << ans << "\n";
}
