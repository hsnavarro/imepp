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

int n, mx;
string s;
vector<string> v;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  while(n--) {
    cin >> s;
    v.pb(s);
  }

  sort(v.begin(), v.end(), [](string a, string b) { return a+b < b+a; });
  string ans;
  for(auto x : v) ans += x;
  cout << ans << "\n";
}

