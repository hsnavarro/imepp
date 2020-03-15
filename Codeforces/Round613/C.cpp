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
const int N = 1e6+5;

ll x, ori;
map<ll, ll> p;

ll fexp(ll b, ll e){
  ll ans = 1;
  while(e){
    if(e & 1ll) ans = (ans*b);
    b = (b*b);
    e = e/2;
  }
  return ans;
}

int main(){
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> x;
  ori = x;
  if(x == 1) cout << "1 1\n";
  else {
    for(ll i = 2; i*i <= x; i++) {
      while(x % i == 0) x = x/i, p[i]++;
    }
    if(x > 1) p[x]++;
    vector<ll> ax;
    for(auto x : p) ax.push_back(fexp(x.st, x.nd));
    ll a, aans, mn = LINF;
    for(ll i = 1; i < (1ll << ax.size()); i++) {
      a = 1;
      for(ll j = 0; j < ax.size(); j++) if(i & (1ll << j)) a *= ax[j];
      if(max(a, ori/a) < mn) mn = max(a, ori/a), aans = a;
    }
    cout << aans << " " << ori/aans << "\n";
  }
}
