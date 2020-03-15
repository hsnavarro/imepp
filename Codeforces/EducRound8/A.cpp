#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define cl(x, v) memset((x), (v), sizeof(x))
#define gcd(x,y) __gcd((x),(y))

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
typedef vector<int> vi;

const ld EPS = 1e-9, PI = acos(-1.);
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 500;

ll pw[10];

ll n, b, p;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n >> b >> p;
  ll aux = n;
  pw[0] = 1;
  for(ll i = 1; i < 10; i++) pw[i] = 2ll*pw[i-1];
  ll k, sum1 = 0, sum2 = 0;
  while (n != 1) {
    for(int i = 9; i >= 0; i--) {
      if(pw[i] <= n) {k = pw[i]; break; }
    }
    sum1 += b*k + k/2;
    n = n-k + k/2;
  }
  cout << sum1 << " " << aux*p << "\n"; 
}
