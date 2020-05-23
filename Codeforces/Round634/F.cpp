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
const int M = 21;
const int N = 1e6 + 5;
 
int t, n, m, nxt[M][N], v[N];
char c[N], s[N];
 
int pass(int u) {
  if(s[u] == 'U') return u-m;
  if(s[u] == 'R') return u+1;
  if(s[u] == 'D') return u+m;
  return u-1;
}
 
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> t;
  while(t--) {
    cin >> n >> m;
    for(int i = 0; i < n*m; i++) v[i] = 0;
    for(int i = 0; i < n*m; i++) cin >> c[i];
    for(int i = 0; i < n*m; i++) cin >> s[i];
 
    for(int i = 0; i < n*m; i++) nxt[0][i] = pass(i);
 
    for(int i = 0; i + 1 < M; i++) 
      for(int j = 0; j < n*m; j++)  nxt[i+1][j] = nxt[i][nxt[i][j]];
 
    for(int i = 0; i < n*m; i++) {
        int prox = nxt[M-1][i];
        if(v[prox] != 2) v[prox] = 1;
        if(c[i] == '0') v[prox] = 2;
    }
 
    int tot = 0, black = 0;
 
    for(int i = 0; i < n*m; i++) {
      if(v[i] == 2) black++;
      if(v[i] > 0) tot++;
    }
 
    cout << tot << " " << black << "\n";
  }
} 
