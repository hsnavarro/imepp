#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define cl(x, v) memset((x), (v), sizeof(x))
#define gcd(x,y) __gcd((x),(y))

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
typedef vector<int> vi;

const ld EPS = 1e-9, PI = acos(-1.);
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 2000 + 5;

// size, mod, can use bigger numbers( = 0) -> how many you can build
ll dp[N][N][2];
ll m, d;
string a, b;

ll add(ll a, ll b) {
  if(a + b >= MOD) return a + b - MOD;
  return a + b;
}

ll sub(ll a, ll b) {
  if(a - b < 0) return a - b + MOD;
  return a - b;
}

ll nxt(ll j, ll k) { 
  return (10*j + k) % m;
}

ll calc(string &s) {
  memset(dp, 0, sizeof dp);
  for(int i = 0; i <= s.size(); i++)
    for(int j = 0; j < m; j++)
      for(int k = 0; k < 2; k++) dp[i][j][k] = 0;

  int big = s[0] - '0';
  for(int k = 0; k <= big; k++) { 
    if(k != d) dp[1][k%m][k == big]++;
  }
  
  for(int i = 1; i < s.size(); i++) {
    for(int j = 0; j < m; j++) {
      big = s[i] - '0';
      
      if(dp[i][j][0]){
        for(int k = 0; k <= 9; k++) {
          if((i % 2 == 0) and k == d) continue;
          if((i % 2 != 0) and k != d) continue;
          dp[i+1][nxt(j, k)][0] = 
            add(dp[i][j][0], dp[i+1][nxt(j, k)][0]);
        }
      }

      if(dp[i][j][1]) {
        for(int k = 0; k <= big; k++) {
          if((i % 2 == 0) and k == d) continue;
          if((i % 2 != 0) and k != d) continue;
          dp[i+1][nxt(j, k)][k == big] =
            add(dp[i][j][1], dp[i+1][nxt(j, k)][k == big]);
        }
      }

    }
  }


  return add(dp[s.size()][0][0], dp[s.size()][0][1]);
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> m >> d;
  cin >> a >> b;
  ll dpa = calc(a), dpb = calc(b);
    
  ll cond = 1, mod = 0;
  for(int i = 0; i < a.size(); i++) {
    mod = nxt(mod, a[i] - '0');
    if((i % 2 == 0) and a[i] - '0' == d) cond = 0;
    if((i % 2 != 0) and a[i] - '0' != d) cond = 0;
  }
  cond = cond & (!mod);

  cout << sub(add(dpb, cond), dpa) << "\n";
}
