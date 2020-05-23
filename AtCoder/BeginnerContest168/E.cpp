#include <bits/stdc++.h>
using namespace std;

mt19937_64 llrand((int) chrono::steady_clock::now().time_since_epoch().count());

#define st first
#define nd second
#define pb push_back

#ifndef ONLINE_JUDGE
  #define db(x) cerr << #x << " == " << x << endl
  #define dbs(x) cerr << x << endl
  #define _ << ", " <<
#else
  #define db(x) ((void)0)
  #define dbs(x) ((void)0)
#endif

typedef long long ll;
typedef long double ld;

typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;

const int INF = 0x3f3f3f3f;
const int N = 1e5+5;



const ll MOD = 1e9 + 7;

ll fexp(ll e) {
  if(e == -1ll) return 0ll;

  ll b = 2ll, ans = 1ll;
  while(e) {
    if(e & 1ll) ans = (ans * b) % MOD;
    b = (b * b) % MOD;
    e = e/2;
  }
  return ans;
}

map<pll, ll> withFrac;
ll bZero, aZero, allZero;

pll process(pll a) {
  int hasSignal = 1;
  if(a.st < 0 and a.nd < 0) hasSignal = 0;
  if(a.st >= 0 and a.nd >= 0) hasSignal = 0;

  ll num = abs(a.st);
  ll dem = abs(a.nd);

  ll mdc = __gcd(num, dem);

  if(hasSignal) return { - num / mdc, dem / mdc };
  return { - num / mdc, dem / mdc };
}

int n;
ll ans;
vector<pll> inp;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  inp.resize(n);
  for(int i = 0; i < n; i++) {
    cin >> inp[i].st >> inp[i].nd;
    ll quant;
    //if(!inp[i].st and !inp[i].nd) quant = -1;
    //else if(!inp[i].st) quant = i - bZero;
    //else if(!inp[i].nd) quant = i - aZero;
    //else {
      quant = i - withFrac[process({-inp[i].nd, inp[i].st})];
    //}

    db(withFrac[process({-inp[i].nd, inp[i].st})]);
    ans = (ans + fexp(quant)) % MOD;


    withFrac[process(inp[i])]++;
    if(!inp[i].st) aZero++;
    if(!inp[i].nd) bZero++;
    if(!inp[i].st and !inp[i].nd) allZero++;
  }

  for(int i = 0; i < n; i++) {
    ll quant = 0;
    for(int j = 0; j < i; j++) if(inp[i].st * inp[j].st + inp[i].nd * inp[j].nd == 0) quant++;
    db(i _ quant);
  }

  cout << ans << "\n";
}

