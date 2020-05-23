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

ll n, m;
vector<ll> b;
vector<ll> p;

set<ll> r, s;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n >> m;
  b.resize(n);
  for(int i = 0; i < n; i++) cin >> b[i];
  p.resize(m);
  for(int i = 0; i < m; i++) cin >> p[i];

  for(int msk = 0; msk < (1 << m); msk++) {
    for(int sub = msk; sub > 0; sub = (sub-1) & msk) {
      ll left = 0, right = 0;
      for(int j = 0; j < m; j++) {
        if(!(msk & (1 << j))) continue;
        if(sub & (1 << j)) left += p[j];
        else right += p[j];
      }
      if(left == right) s.insert(left+right);
    }
  }

  s.insert(0);
  for(int i = 0; i < n; i++) {
    for(auto x : s) r.insert(x + b[i]);
  }

  for(auto x : r) cout << x << "\n";
}
