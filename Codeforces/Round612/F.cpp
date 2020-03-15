#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define st first
#define nd second
#define pb push_back

const int MOD = 998244353;
const int N = 1e5 + 5;

// time, prob hap
map<ll, ll> mp;
map<ll, pair<ll, ll>> frac;

ll fexp(ll b, ll e) {
  ll ans = 1;
  while(e) {
    if(e & 1ll) ans = (ans*b) % MOD;
    b = (b*b) % MOD;
    e = e/2;
  }
  return ans;
}

ll mult(ll a, ll b) { return (a*b) % MOD; }
ll dv(ll a, ll b) { return mult(a, fexp(b, MOD-2)); } 
ll sum(ll a, ll b) { return (a+b)% MOD; }
ll sub(ll a, ll b) { return (a-b+MOD) % MOD; }

ll n, x[N], v[N], p[N];

pair<ll, ll> find_frac(ll e) {
  for(ll i = 1; i <= 1000; i++){
    for(ll j = 1; j <= 1000; j++) if(dv(i, j) == e) return {i, j};
  }
  return {-1, -1};
}

bool cmp (pair<ll, ll> a, pair<ll, ll> b) {
  pair<ll, ll> frac_a = frac[a.st];
  pair<ll, ll> frac_b = frac[b.st];
  return frac_a.st * frac_b.nd < frac_a.nd * frac_b.st;
}

int main(){
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  if(n == 1) return cout << "0\n", 0;
  for(int i = 1; i <= n; i++) {
    cin >> x[i] >> v[i] >> p[i];
    p[i] = dv(p[i], 1ll*100);
    //cout << "p " << p[i] << endl;
  }
  for(int i = 1; i+1 <= n; i++) {
    ll time, prob;
    // right, left
    time = dv(sub(x[i+1], x[i]), sum(v[i+1], v[i]));
    prob = mult(p[i], sub(1, p[i+1]));
    //cout << "time, prob " << time << " " << prob << "\n";
    mp[time] += prob;
    frac[time] = {sub(x[i+1], x[i]), sum(v[i+1], v[i])};
    // right, right
    if(v[i] > v[i+1]) {
      //cout << "entered right right\n";
      time = dv(sub(x[i+1], x[i]), sub(v[i], v[i+1]));
      prob = mult(p[i], p[i+1]);
      mp[time] += prob;
      frac[time] = {sub(x[i+1], x[i]), sub(v[i], v[i+1])};
    }
    // left, left
    if(v[i+1] > v[i]) {
      //cout << "entered left left\n";
      time = dv(sub(x[i+1], x[i]), sub(v[i+1], v[i]));
      prob = mult(sub(1, p[i]), sub(1, p[i+1]));
      mp[time] += prob;
      frac[time] = {sub(x[i+1], x[i]), sub(v[i+1], v[i])};
    }
  }

  vector<pair<ll, ll>> v;
  for(auto x : mp) v.push_back({x.st, x.nd});
  sort(v.begin(), v.end(), cmp);

  cout << "debug" << endl;
  for(auto x : v) {
    auto ans = find_frac(x.st);
    cout << ans.st << " " << ans.nd << endl;
  }
  

  pair<ll, ll> m = {1ll, 1ll}, a = {0, 1ll};
  ll mul = 1, ans = 0;
  for(int i = 0; i < v.size(); i++) {
    if(i-1 >= 0) {
      mul = dv(mul, v[i-1].nd);
      mul = mult(mul, sub(1, v[i-1].nd));
    }
    mul = mult(mul, v[i].nd);
    ans = sum(ans, mult(mul, v[i].st));
  }
  cout << ans << "\n";
}
