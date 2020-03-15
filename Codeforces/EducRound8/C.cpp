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

int n, k;
string s;

char find(char x, int val) {
  int aux = x - 'a';
  if(aux - val >= 0) return char(aux - val + 'a');
  if(aux + val < 26) return char(aux + val + 'a');
  return '#';
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n >> k;
  cin >> s;
  int sum = 0;
  string ans;
  for(int i = 0; i < n; i++) {
    int aux = s[i] - 'a';
    int mx = max(aux, 25 - aux);
    ans += find(s[i], min(k, mx)); 
    k -= min(k, mx);
  }
  if(k) cout << -1 << "\n";
  else cout << ans << "\n";
}
