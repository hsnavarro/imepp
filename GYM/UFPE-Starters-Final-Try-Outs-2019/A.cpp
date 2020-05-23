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
const int N = 1e4+5;

int n, m, k;
vector<int> v[10];

void build() {
  v[1] = {6, 8};
  v[2] = {7, 9};
  v[3] = {4, 8};
  v[4] = {0, 3, 9};
  v[6] = {1, 7, 0};
  v[7] = {2, 6};
  v[8] = {1, 3};
  v[9] = {2, 4};
  v[0] = {4, 6};
} 

ll add(ll a, ll b) {
  a += b;
  if(a > MOD) return a - MOD;
  return a;
}

ll dp[N][15][105];
string t;
int lps[105];

void prekmp() {
  for(int i = 1, j = 0; i < t.size(); i++) {
    while(j > 0 and t[i] != t[j]) j = lps[j-1];
    if(t[i] == t[j]) j++;
    if(j == t.size()) j = lps[j-1];
    lps[i] = j;
  }
}

int next(int pos, int x) {
  if(!t.size()) return 0;
  char a = x + '0';
  while(pos > 0 and t[pos] != a) pos = lps[pos-1];
  if(t[pos] == a) pos++;
  return pos;
}


int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  build();
  cin >> n >> m >> k;
  cin >> t;
  prekmp();

  m = max(m, 1);
  dp[0][k][0] = 1;
  for(int i = 0; i+1 <= n; i++) {
    for(int ch = 0; ch < 10; ch++) {
      for(int pos = 0; pos < m; pos++) {
        for(auto x : v[ch]) {
          if(next(pos, x) == m) continue;
          dp[i][x][next(pos, x)] = add(dp[i+1][x][next(pos, x)], dp[i][ch][pos]);
        }
      }
    }
  }

  ll ans = 0;
  for(int x = 0; x < 10; x++)
    for(int pos = 0; pos < m; pos++) ans = add(ans, dp[n][x][pos]);

  cout << ans << "\n";
}

