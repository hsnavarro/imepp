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
const int N = 2e3+5;

vector<int> ans, ori, idxs;
ll n, mx;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  ori.resize(n);
  for(int i = 0; i < n; i++) cin >> ori[i];

  for(int i = 0; i < n; i++) idxs.pb(i);
  
  int cnt = 0;

  do {
    ll aj, sum = 0;

    for(int i = 0; i < n; i++) {
      for(int j = 0; j < idxs.size(); j++) if(idxs[j] == i) aj = j;
      sum += abs(i - aj) * ori[i];
    }

    if(sum > mx) mx = sum, ans = idxs;

    

  }while(next_permutation(idxs.begin(), idxs.end()));

  db(mx);
  for(auto x : ans) cout << x+1 << " ";
  cout << "\n";

}

