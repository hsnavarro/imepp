#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define st first
#define nd second

const ll MOD = 998244353;
const int N = 1e5 + 5;

struct frac {
  ll num, dem;
  frac () : num(0ll), dem(1ll) {}

  frac (ll x, ll y) {
    ll gcd = __gcd(x, y);
    num = x/gcd;
    dem = y/gcd;
  } 
  frac operator+ (frac b) {
    return frac(num*b.dem + dem*b.num, dem*b.dem);
  }
  frac operator- (frac b) {
    return frac(num*b.dem - dem*b.num, dem*b.dem);
  }
  frac operator/ (frac b) {
    return frac(num*b.dem, dem*b.num);
  }
  frac operator* (frac b) {
    return frac(num*b.num, dem*b.dem);
  }
};

bool operator< (const frac a, const frac b) {
  return a.num*b.dem < a.dem*b.num;
}

ll inv(ll b) {
  ll ans = 1, e = MOD-2;
  while(e){
    if(e & 1ll) ans = (ans*b) % MOD;
    b = (b*b) % MOD;
    e = e/2;
  }
  return ans;
}

ll calc(ll x, ll y) {
  return (x*inv(y)) % MOD;
}

ll n, x[N], v[N], p[N];
frac prob[N];
map<frac, frac> mp;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  for(int i = 1; i <= n; i++){
    cin >> x[i] >> v[i] >> p[i];
    prob[i] = frac(p[i], 1ll*100);
  }
  if(n == 1) return cout << "0\n", 0;
  frac time, prb, one = frac(1, 1);
  for(int i = 1; i+1 <= n; i++) {
    time = frac(x[i+1] - x[i], v[i] + v[i+1]);
    prb = prob[i]*(one - prob[i+1]);
    mp[time] = mp[time] + prb;
    if(v[i] > v[i+1]) {
      time = frac(x[i+1] - x[i], v[i] - v[i+1]);
      prb = prob[i]*prob[i+1];
      mp[time] = mp[time] + prb;
    }
    if(v[i+1] > v[i]) {
      time = frac(x[i+1] - x[i], v[i+1] - v[i]);
      prb = (one - prob[i])*(one - prob[i+1]);
      mp[time] = mp[time] + prb;
    }
  }

  vector<pair<frac, frac>> v;
  for(auto x : mp) v.push_back({x.st, x.nd});

  frac mul = {1ll, 1ll}, ans = {0ll, 1ll};
  for(int i = 0; i < v.size(); i++) {
    if(i-1 >= 0) {
      mul = mul/v[i-1].nd;
      mul = mul*(one - v[i-1].nd);
    }
    mul = mul*v[i].nd;
    ans = ans + (mul*v[i].st);
  }
  cout << ans.num << " " << ans.dem << "\n";
  cout << calc(ans.num, ans.dem) << "\n";
}
