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

int n, m, k;
int sx, sy, fx, fy;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n >> m >> k;
  int aux = k;
  while(aux--) cin >> sx >> sy;
  aux = k;
  while(aux--) cin >> fx >> fy;
  string s;

  int nn = n-1, mm = m-1;
  while(nn--) s += 'U';
  while(mm--) s += 'L';
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      if(i == n-1 and j == m-1) continue;
      else if(j == m-1) s += 'D';
      else {
        if(i & 1) s += 'L';
        else s += 'R';
      }
    }
  }

  cout << s.size() << "\n";
  cout << s << "\n";
}
