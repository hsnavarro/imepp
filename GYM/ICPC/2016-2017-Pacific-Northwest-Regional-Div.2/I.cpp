#include <bits/stdc++.h>
using namespace std;

mt19937_64 llrand((int) std::chrono::steady_clock::now().time_since_epoch().count());

#define st first
#define nd second
#define pb push_back

#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define _ << ", " <<

typedef long long ll;
typedef long double ld;

typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;

const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e5+ 5;

ll n, k, ans;
priority_queue<ll> pq;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  ll sum = 0, mx = 0;
  while(n--) {
    cin >> k;
    sum += k;
    mx = max(mx, k);
  }

  if(2*mx > sum) cout << sum-mx << "\n";
  else cout << sum/2 << "\n";
}

