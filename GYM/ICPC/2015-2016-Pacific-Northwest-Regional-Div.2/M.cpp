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

int n, x;
string s;
vector<pair<string, int>> inp;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  while(n--) {
    cin >> s >> x;
    inp.push_back({s, x});
  }

  int cnt = 0;
  for(int k = 1; k <= 100; k++) {
    int start = k;
    for(auto pp : inp) {
      if(pp.st == "ADD") start += pp.nd;
      if(pp.st == "SUBTRACT") start -= pp.nd;
      if(pp.st == "DIVIDE") {
        if(start % pp.nd != 0) { cnt++; break; }
        start /= pp.nd;
      }
      if(pp.st == "MULTIPLY") start *= pp.nd;

      if(start < 0) {
        cnt++;
        break;
      }
    }
  }

  cout << cnt << "\n";
}

