#include <bits/stdc++.h>
using namespace std;

#define int long long

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
typedef vector<vi> vii;

const ld EPS = 1e-9, PI = acos(-1.);
const ll LINF = 0x3f3f3f3f3f3f3f3f, LMOD = 1011112131415161719ll;
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e5+5;

int t, a, b, n, fib[3];

int32_t main(){
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> t;
  while(t--){
    cin >> a >> b >> n;
    fib[0] = a;
    fib[1] = b;
    fib[2] = a^b;
    cout << fib[n%3] << "\n";
  }

}
