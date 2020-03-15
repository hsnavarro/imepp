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
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int N = 1e5+5;

ll t, n, a[N], s1, s2;
vector<pair<ll, pair<ll, ll>> > ans;

int main(){
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> t;
  while(t--){
    ans.clear();
    s1 = 0, s2 = 0;
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i], s1 += a[i];
    ll l = 1;
    for(int i = 1; i <= n; i++) {
      s2 += a[i];
      ans.push_back({s2, {l, i}});
      if(s2 < 0) s2 = 0, l = i+1;
    }
    ll r = n;
    s2 = 0;
    for(int i = n; i >= 1; i--){
      s2 += a[i];
      ans.push_back({s2, {i, r}});
      if(s2 < 0) s2 = 0, r = i-1;
    } 
    sort(ans.begin(), ans.end());
    while(ans.back().nd.st == 1 and ans.back().nd.nd == n) ans.pop_back();
    //cout << "l, r " << ans.back().nd.st << " " << ans.back().nd.nd << endl;
    s2 = ans.back().st;
    //cout << "s1, s2 " << s1 << " " << s2 << endl;
    if(s1 > s2) cout << "YES\n";
    else cout << "NO\n";
  }
}
