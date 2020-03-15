#include <bits/stdc++.h>
using namespace std;
 
#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define cl(x, v) memset((x), (v), sizeof(x))
 
#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define _ << ", " <<
 
typedef long long ll;
typedef long double ld;
 
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
 
const ld EPS = 1e-9, PI = acos(-1.);
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int N = 2e5+5;
const ll MOD = 1e9 + 7;

ll n, m, dp[25][1005];

ll add(ll a, ll b) { return (a+b)%MOD; };

int main(){
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n >> m;
  for(int pos = 1; pos <= 2*m; pos++){
    for(int last = 1; last <= n; last++){
      if(pos == 1) dp[pos][last] = 1;
      else for(int j = 1; j <= last; j++) 
        dp[pos][last] = add(dp[pos][last], dp[pos-1][j]);
    }
  }
  ll ans = 0;
  for(int i = 1; i <= n; i++) ans = add(ans, dp[2*m][i]);

  cout << ans << "\n";
}
