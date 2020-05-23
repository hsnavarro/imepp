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
const int N = 1e2 + 5;

int dp[N+1][N+1][N+1][2];
string build;

int n1, n2, n3, t;

void recover(int i, int j, int k, int p) {
  build += to_string(p);
  if(!i and !j and !k) return;

  if(j and !p and dp[i][j-1][k][1]) recover(i, j-1, k, 1);
  else if(k and p and dp[i][j][k-1][1]) recover(i, j, k-1, 1);
  else if(i and !p and dp[i-1][j][k][0]) recover(i-1, j, k, 0);
  else if(j and p and dp[i][j-1][k][0]) recover(i, j-1, k, 0);
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  dp[0][0][0][1] = 1;
  dp[0][0][0][0] = 1;

  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) {
      for(int k = 0; k < N; k++) {
        // 1, 0
        dp[i][j+1][k][0] = 1;
        // 1, 1
        dp[i][j][k+1][1] = 1;
        // 0, 0
        dp[i+1][j][k][0] = 1;
        // 0, 1
        dp[i][j+1][k][1] = 1;
      }
    }
  }

  cin >> t;
  while(t--) {
    cin >> n1 >> n2 >> n3;
    build.clear();
    if(dp[n1][n2][n3][1]) recover(n1, n2, n3, 1);
    else recover(n1, n2, n3, 0);

    cout << build << "\n";
  }
}

