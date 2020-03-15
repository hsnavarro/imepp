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
const int N = 3e5+5, M = 8+5;

int n, m, a[N][M];
pair<int, int> ans;

bool test(int x) {
  map<int, int> p;
  // mask, idx
  for(int i = 1; i <= n; i++) {
    int msk = 0;
    for(int j = 1; j <= m; j++) if(a[i][j] >= x) msk += (1 << (j-1));
    p[msk] = i;
  }

  for(auto x : p) {
    for(auto y : p) {
      if((x.st | y.st) == ((1 << m) - 1)) {
        ans = {x.nd, y.nd};
        return true;
      }
    }
  }
  return false;
}

int bin(int l = 0, int r = (int) 1e9 + 5) {
  int mid;
  while(l != r) {
    mid = (l+r)/2;
    if(test(mid)) l = mid+1;
    else r = mid;
  }
  return l-1;
}


int main(){
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n >> m;
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= m; j++) cin >> a[i][j];
  }

  test(bin());
  cout << ans.st << " " << ans.nd << "\n";
}
