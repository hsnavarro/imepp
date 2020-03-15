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
const int N = 2e5+5;

ll t, a, b;

ll fexp(ll b, ll e){
  ll ans = 1;
  while(e) {
    if(e & 1ll) ans = ans*b;
    b = b*b;
    e = e/2;
  }
  return ans;
}

ll conc(ll i, ll j) {
  string a = to_string(j);
  return i*fexp(10*1ll, (ll) a.size())+j;
}

ll cnt(ll x) {
  string a = "9";
  ll cnt = 0;
  while(stoll(a) <= x) a += '9', cnt++;
  return cnt;
}

int main(){
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> t;
  while(t--){
    cin >> a >> b;
    cout << a*cnt(b) << "\n";
  }
}
