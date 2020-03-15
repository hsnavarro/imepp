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
const int N = 1e2+5;

// dp[pos][num_imp][num_par][par ou impar];

int n, imp, par, a[N], dp[N][N][N][2];
set<int> s;

int dpf(int pos, int imp, int par, int isPar) {
  if(pos == n+1) return 0;
  if(dp[pos][imp][par][isPar] != -1) return dp[pos][imp][par][isPar];
  int dpval = INF;
  if(a[pos]) {
    if(a[pos] & 1) {
      if(pos == 1 or !isPar) dpval = dpf(pos+1, imp, par, 0);
      else dpval = 1 + dpf(pos+1, imp, par, 0);
    } else {
      if(pos == 1 or isPar) dpval = dpf(pos+1, imp, par, 1);
      else dpval = 1 + dpf(pos+1, imp, par, 1);
    }
  } else {
    if(imp) {
      if(pos == 1 or !isPar) dpval = min(dpval, dpf(pos+1, imp-1, par, 0));
      else dpval = min(dpval, 1 + dpf(pos+1, imp-1, par, 0));
    }
    if(par) {
      if(pos == 1 or isPar) dpval = min(dpval, dpf(pos+1, imp, par-1, 1));
      else dpval = min(dpval, 1 + dpf(pos+1, imp, par-1, 1));
    }
  }

  return dp[pos][imp][par][isPar] = dpval;
}

int main(){
  ios_base::sync_with_stdio(0), cin.tie(0);
  memset(dp, -1, sizeof dp);
  cin >> n;
  for(int i = 1; i <= n; i++) cin >> a[i], s.insert(a[i]);

  for(int i = 1; i <= n; i++) {
    if(!s.count(i)) {
      if(i & 1) imp++;
      else par++;
    }
  }
  
  cout << dpf(1, imp, par, -1) << "\n";
}
