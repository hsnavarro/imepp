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
const int N = 1e5+5;


vector<int> calc(int n) {
  vector<int> v;
  for(int i = 1; i <= n; i++) v.pb(i);
  do {
    int cond = 1;
    for(int i = 0; i+1 <= n; i++) if(abs(v[i+1] - v[i]) > 4 or abs(v[i+1] - v[i]) < 2) cond = 0;
    if(cond) {
      for(auto x : v) cout << x << " ";
      cout << "\n";
    }
  }while(next_permutation(v.begin(), v.end()));
  
  return {-1};
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int t, n;
  cin >> t;
  while(t--) {
    cin >> n;
    if(n <= 3) cout << "-1\n";
    else if(n == 4) cout << "3 1 4 2\n";
    else {
      int i;
      for(i = 1; i <= n; i+=2) cout << i << " ";
      i -= 2;
      cout << i-3 << " ";
      for(int j = (n&1 ? n-1 : n); j > 0; j -= 2) if(j != i-3) cout << j << " ";
      cout << "\n";
    }
  }
}

