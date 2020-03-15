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
const int N = 1e5+5;

string s;
vector<vector<int>> ans;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> s;
  while(1) {
    vector<int> aux;
    int l = 0, r = s.size() - 1;
    while(l < r) {
      while(l < s.size() and s[l] != '(') l++;
      while(r >= 0 and s[r] != ')') r--;
      if(l < r) s[l] = '#', s[r] = '#', aux.pb(l+1), aux.pb(r+1), l++, r--;
    }
    if(!aux.size()) break;
    sort(aux.begin(), aux.end());
    ans.pb(aux);
  }
  cout << ans.size() << "\n";
  for(auto v : ans) {
    cout << v.size() << "\n";
    for(auto x : v) cout << x << " ";
    cout << "\n";
  } 
}
