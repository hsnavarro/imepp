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
const int N = 1e3+ 5;

ll n, k, x[N], m[N], ans;
vector<int> v1, v2;


void solve(vector<int> &v) {
  sort(v.begin(), v.end(), [](int a, int b) { return x[a] < x[b]; });
  int p = v.size() - 1;
  while(p >= 0) {
    int i = v[p]; 
    if(!m[i])  {
      p--;
      continue;
    }

    if(m[i] % k == 0) ans += x[i]*2ll*m[i]/k;
    else {
      ans += x[i]*2ll*(m[i]/k+1);
      ll rest = k - m[i]%k;
      ll aux = p-1;
      while(aux >= 0 and rest > 0) {
        if(rest >= m[v[aux]]) rest -= m[v[aux]], m[v[aux]] = 0;
        else m[v[aux]] -= rest, rest = 0;
        aux--;
      }
    }
    p--;
  }
} 

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n >> k;
  for(int i = 1; i <= n; i++) {
    cin >> x[i] >> m[i];

    if(x[i] > 0) v1.pb(i);
    else if(x[i] < 0) {
      x[i] = -x[i];
      v2.pb(i);
    }
  }
  solve(v1);
  solve(v2);
  cout << ans << "\n";
}
