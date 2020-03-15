#include <bits/stdc++.h>
using namespace std;

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
const int N = 1e3+5;

int lf[N], rt[N];
string s;
vector<vector<int>> ans;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> s;
  int n = s.size(), mx;
  while(1) {
    mx = 0;
    for(int i = 1; i <= n; i++) lf[i] = (s[i-1] == '(') + lf[i-1];
    for(int i = n; i >= 1; i--) rt[i] = (s[i-1] == ')') + rt[i+1];

    for(int i = 1; i <= n; i++) mx = max(mx, min(lf[i], rt[i+1]));

    if(!mx) break;
    vector<int> aux;
    int val1 = mx, val2 = mx;
    for(int i = 0; i < n; i++) {
      if(val1 and s[i] == '(') s[i] = '#', aux.pb(i+1), val1--;
      if(!val1 and val2 and s[i] == ')') s[i] = '#', aux.pb(i+1), val2--;
    }
    ans.pb(aux);
  }
  cout << ans.size() << "\n";
  for(auto v : ans) {
    cout << v.size() << "\n";
    for(auto x : v) cout << x << " ";
    cout << "\n";
  }
}
