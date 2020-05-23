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

bool cmp(pair<string, string> a, pair<string, string> b) {
  if(a.nd == b.nd) return a.st < b.st;
  return a.nd < b.nd;
}

int n;
string s, t;
vector<pair<string, string>> inp;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  while(n--) {
    cin >> s >> t;
    inp.pb({s, t});
  }

  sort(inp.begin(), inp.end(), cmp);

  for(auto x : inp) cout << x.st << " " << x.nd << "\n";
}

