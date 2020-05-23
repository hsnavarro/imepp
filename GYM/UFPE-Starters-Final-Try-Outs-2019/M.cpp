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

// 0 a l-1 + r+1 a n
// l a r
// r - l + 1 == sz/2
// r = sz/2 + l - 1

int sa[N], sb[N];
string s;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> s;
  int sz = s.size();
  if(sz & 1) return cout << "NO\n", 0;
  else {
    for(int i = 1; i <= sz; i++) {
      sa[i] = (s[i-1] == 'A') + sa[i-1];
      sb[i] = (s[i-1] == 'B') + sb[i-1];
    }

    for(int l = 1; l + sz/2 - 1 < sz; l++) {
      int r = l + sz/2 - 1;
      int a1 = sa[l-1] + sa[sz] - sa[r];
      int b1 = sb[l-1] + sb[sz] - sb[r];

      int a2 = sa[r] - sa[l-1];
      int b2 = sb[r] - sb[l-1];
      if(a1 == a2 and b1 == b2) {
        cout << "YES\n";
        cout << l << " " << r+1 << "\n";
        return 0;
      }
    }
  }
  cout << "NO\n";
}

