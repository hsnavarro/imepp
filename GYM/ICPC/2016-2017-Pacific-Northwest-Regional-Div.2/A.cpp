#include <bits/stdc++.h>
using namespace std;

mt19937_64 llrand((int) std::chrono::steady_clock::now().time_since_epoch().count());

#define st first
#define nd second
#define pb push_back

#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define _ << ", " <<

typedef long long ll;
typedef long double ld;

typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;

const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 50+ 5;

string alf = "abcdefghijklmnopqrstuvwxyz";
string s;

int dp[N][N];

int calcdp(int i, int j) {
  if(dp[i][j] != -1) return dp[i][j];
  if(j == alf.size()) return dp[i][j] = 0;
  if(i == s.size()) return alf.size() - j;

  if(s[i] == alf[j]) return dp[i][j] = calcdp(i+1, j+1);
  return dp[i][j] = min(1 + calcdp(i, j+1), calcdp(i+1, j));
}


int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> s;
  memset(dp, -1, sizeof dp);
  cout << calcdp(0, 0) << "\n";
}
