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
const int N = 1e5+5;

string s;
ll sum = 0;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> s;
  for(auto x : s) {
    if((x - '0') % 4 == 0) sum++;
  }

  for(int i = 0; i+1 < s.size(); i++) {
    ll a = s[i] - '0', b = s[i+1] - '0';
    if((10ll*a + b) % 4 == 0) sum += i+1;
  }
  cout << sum << "\n";
}
