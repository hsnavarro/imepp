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

ll n, k, pt, tmp, ans;
vector<ll> t;
multiset<ll> s;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n >> k;
  t.resize(n);
  for(int i = 0; i < n; i++) cin >> t[i];
  while(pt < k) {
    s.insert(t[pt]);
    pt++;
  }

  while(s.size()) {
    auto it = s.begin();
    int val = *(it);

    ans += tmp + val;
    tmp += val;

    s.erase(s.find(val));

    if(pt < n) s.insert(t[pt]), pt++;
  }

  cout << ans << "\n";

}
