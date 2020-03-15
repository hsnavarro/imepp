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
const int N = 1e5+5;

ll t, n, m, a[N], b[N], prof[N];

int main(){
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> t;
  while(t--) {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i], prof[a[i]] = i-1;
    for(int i = 1; i <= m; i++) cin >> b[i];
    ll time = 0, mx_prof = 0;
    for(int i = 1; i <= m; i++) {
      time++;
      if(prof[b[i]] > mx_prof) {
        mx_prof = prof[b[i]];
        time += (mx_prof - i + 1)*2ll;
      }
    }
    cout << time << "\n";
  }
}
