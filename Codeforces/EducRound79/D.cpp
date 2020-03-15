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
const int N = 1e6+5;
const ll MOD = 998244353;
 
ll fexp(ll b) {
  ll ans = 1, e = MOD-2;
  while(e){
    if(e & 1ll) ans = (ans*b) % MOD;
    b = (b*b) % MOD;
    e = e/2;
  }
  return ans;
}
 
ll ans(ll x, ll y) { return x*fexp(y) % MOD; }
ll sum(ll x, ll y) { return (x+y)%MOD; }
ll mul(ll x, ll y) { return (x*y) % MOD; }
 
ll n, k[N], cnt[N], a;
vector<ll> op[N];
 
int main(){
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  for(int i = 1; i <= n; i++) {
    cin >> k[i];
    for(int j = 0; j < k[i]; j++) cin >> a, cnt[a]++, op[i].pb(a);
  }
 
  ll resp = 0;
  for(int i = 1; i <= n; i++) {
    for(auto x : op[i]) {
      resp = sum(resp, ans(cnt[x], mul(n, mul(n, k[i]))));
    }
  }
  cout << resp << "\n";
}
