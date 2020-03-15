#include <bits/stdc++.h>
using namespace std;

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

const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 2e5 + 5, M = 1e6+5;

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

// worst case -> n
// n/2 elements with -1, 0, 1

// max number of primes in a 10^12 number -> 12 

ll n, ans, a[N];

// O(3 * (sqrt(n) + 12*N))

vector<ll> find_prime(ll n) {
  vector<ll> ans;
  for(ll i = 2; i*i <= n; i++) {
    if(n % i == 0) {
      ans.pb(i);
      while(n % i == 0) n = n/i;
    }
  }
  if(n > 1) ans.pb(n);
  return ans;
}

ll find_ans(vector<ll> &v) {
  ll res = 0, best = n;
  for(auto x : v) {
    res = 0;
    for(int i = 0; i < n; i++) {
      ll op1 = (a[i]/x) * x;
      ll op2 = op1 + x;
      if(!op1) res += abs(op2 - a[i]);
      else res += min(abs(op1 - a[i]), abs(op2 - a[i]));
    }
    best = min(best, res);
  }
  return best;
}

void test(int x) {
  ll val = a[x];
  vector<ll> ps;
  ps = find_prime(val);
  ans = min(ans, find_ans(ps));
  ps = find_prime(val+1);
  ans = min(ans, find_ans(ps));
  if(val-1) {
    ps = find_prime(val-1);
    ans = min(ans, find_ans(ps));
  }
}


int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  ans = n;
  vector<int> aux;
  for(int i = 0; i < n; i++) cin >> a[i], aux.pb(i);
  shuffle(aux.begin(), aux.end(), rng);
  for(int i = 0; i < min(45, int(n)); i++) test(aux[i]);
  cout << ans << "\n";
}
