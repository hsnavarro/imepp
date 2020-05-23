#include <bits/stdc++.h>
using namespace std;

mt19937_64 llrand((int) std::chrono::steady_clock::now().time_since_epoch().count());

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
const int N = 5e2+5;


int n, m, a[N][N], dp[N][N];

void bobs(int n, int m) {
  for(int i = 0; i <= n; i++)
    for(int j = 0; j <= m; j++) dp[i][j] = 0;
  dp[0][1] = a[1][1];

  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= m; j++) dp[i][j] = max(dp[i-1][j] & a[i][j], dp[i][j-1] & a[i][j]);
  } 
}

vector<pair<int, int>> v;

void rec(int i, int j) {
  if(!i or !j) return;
  v.pb({i, j});
  if(i and (dp[i-1][j] & a[i][j]) == dp[i][j]) rec(i-1, j);
  else if(j and (dp[i][j-1] & a[i][j]) == dp[i][j]) rec(i, j-1);
}

string dbug(int x) {
  string s;
  for(int i = 0; i < 20; i++) {
    if(x & (1 << i)) s += '1';
    else s += '0';
  }
  return s;
}


int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  ll k;
  cin >> k;
  //cin >> n >> m;
  //for(int i = 1; i <= n; i++)
  //  for(int j = 1; j <= m; j++) cin >> a[i][j];
  
  cout << 3 << " " << 5 << "\n";
  for(int i = 0; i <= 3; i++) {
    for(int j = 0; j <= 5; j++) a[i][j] = 0;
  }

  ll all = (1ll << 18) - 1;
  ll p = (~k & all);
  if(!(p & (1 << 17))) p += (1 << 17);

  a[1][1] = a[1][2] = a[1][3] = all;
  a[2][1] = p;
  a[3][1] = a[3][2] = p;
  a[3][3] = all;
  a[3][5] = all;
  a[2][3] = k;
  a[3][4] = (~p & all);

  for(int i = 1; i <= 3; i++) {
    for(int j = 1; j <= 5; j++) cout << a[i][j] << " ";
    cout << "\n";
  }
  //cout << p << "\t" << dbug(p) << "\n";
  //cout << k << "\t" << dbug(k) << "\n";
  //cout << a[3][4] << "\t" << dbug(a[3][4]) << "\n";
  //cout << all << "\t" << dbug(all) << "\n";

  //bobs(n, m);
  //cout << dp[n][m] << "\n";
}

