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
const int N = 2e3+5;

bool used[N];
ll n, ans, a[N];
vector<int> idxs;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  for(int i = 1; i <= n; i++) cin >> a[i], idxs.pb(i);

  sort(idxs.begin(), idxs.end(), [](int a, int b) { return idxs[a] > idxs[b]; });
  
  for(int i = 0; i < idxs.size(); i++) {
    ll mx = 0, idx_mx;
    for(int j = 1; j <= n; j++) {
      if(used[j]) continue;
      if(abs(idxs[i] - j) > mx) {
        mx = abs(idxs[i] - j);
        idx_mx = j;
      } 
    }
    ans += a[idxs[i]]*mx;
    used[idx_mx] = 1;
  }

  cout << ans << "\n";





}

