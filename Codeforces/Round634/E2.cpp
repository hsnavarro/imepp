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
const int N = 2e5+5;
 
const int M = 200 + 5;
 
int t, n, a[N], pref[N][M];
vector<int> pos[M];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> t;
  while(t--) {
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];

    for(int j = 0; j < M; j++) pos[j].clear();
    for(int i = 0; i <= n+1; i++)
      for(int j = 0; j < M; j++) pref[i][j] = 0;
 
    for(int i = 1; i <= n; i++)
      for(int j = 1; j < M; j++) {
          pref[i][j] = pref[i-1][j];
          if(a[i] == j) pref[i][j]++, pos[j].pb(i);
      }
 
    int mx = -1;
    for(int k = 0; k < M; k++) {
        mx = max(mx, pref[n][k]);
        for(int x = 0; x < pref[n][k]; x++) {
          if(x >= pref[n][k] - 1 - x) break;

          int l = pos[k][x];
          int r = pos[k][pref[n][k] - 1 - x];

          for(int y = 0; y < M; y++) mx = max(mx , 2*(x+1) + pref[r-1][y] - pref[l][y]);
        }
    }
    
    cout << mx << "\n";
  } 
}
