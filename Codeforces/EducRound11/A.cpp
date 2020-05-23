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

const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e7+5;

int n;
vector<int> p;
int cmp[N];

void sieve() {
  for(ll i = 2; i < N; i++) {
    if(!cmp[i]) {
      p.pb(i);
      for(ll j = i*i; j < N; j += i) cmp[j] = 1;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  sieve();
  cin >> n;
  vector<int> a(n);
  for(int i = 0; i < n; i++) cin >> a[i];
  vector<int> ans;

  for(int i = 0; i + 1 < n; i++) {
    ans.pb(a[i]);
    if(__gcd(a[i], a[i+1]) == 1) continue;
    else {
      for(auto x : p) {
        if(__gcd(a[i], x) == 1 and __gcd(a[i+1], x) == 1) {
          ans.pb(x);
          break;
        }
      }
    
    }
  }
  ans.pb(a[n-1]);
  
  cout << ans.size() - n << "\n";
  for(auto x : ans) cout << x << " ";
  cout << "\n";
}

