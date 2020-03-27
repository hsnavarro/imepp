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

vector<pll> v;
map<ll, ll> freq;
ll c, m, t, x;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> t;
  while(t--) {
    cin >> c >> m;
    v.clear(), freq.clear();
    while(c--) cin >> x, freq[x]++;
    for(auto x : freq) v.pb({x.st*x.nd, x.st});
    sort(v.begin(), v.end());
    ll sum = 0;
    vector<int> ans;
    for(int i = v.size() - 1; i >= 0; i--) {
      sum += v[i].st;
      ans.pb(v[i].nd);
      if(sum >= m) break;
    }
    if(sum < m) cout << "Impossible\n";
    else {
      sort(ans.begin(), ans.end());
      for(auto x : ans) cout << x << " ";
      cout << "\n";
    }
  }
}

