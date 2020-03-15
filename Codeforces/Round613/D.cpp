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

int p[40];

ll a;
vector<ll> v;

void see(ll a){
  for(int i = 0; i <= 30; i++) if(a & (1ll << i)) p[i]++;
}

int main(){
  ios_base::sync_with_stdio(0), cin.tie(0);
  int n;
  cin >> n;
  while(n--) cin >> a, v.pb(a), see(a);
  ll ans = 0;
  for(int i = 0; i < 40; i++) if(p[i] and p[i] % 2 == 0) ans += (1ll << i);
  ll mx = 0;
  for(auto x : v) mx = max(mx, x^ans);
  cout << mx << "\n";
}
