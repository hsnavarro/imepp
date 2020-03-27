#include <bits/stdc++.h>
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

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
const int N = 1e5+5;

ll na, nb, n, k;
int t;

ll calc(ll na, ll nb) {
  ll n = na + nb;
  if(nb == 2) return (n*(n-1))/2;
  if(nb == 1) return n;
  return 1;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> t;
  while(t--) {
    string s;
    cin >> n >> k;
    na = n-2, nb = 2;
    while(na or nb) {
      if(!na) s += 'b', nb--;
      else if(k > calc(na-1, nb)) s += 'b', k -= calc(na-1, nb), nb--;
      else s += 'a', na--;
    }
    cout << s << "\n";

  }
}

