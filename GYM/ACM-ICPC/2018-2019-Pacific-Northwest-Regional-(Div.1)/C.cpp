#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define pb push_back

typedef long long ll;

const int N = 1000 + 5;
const int MOD = 998244353;

ll n, k;
ll dp[N][N], a[N], aux[N];
map<int, ll> cnt;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n >> k;
  for(int i = 1; i <= n; i++) cin >> a[i], cnt[a[i]]++;
  int pos = 0;
  for(auto x : cnt) aux[++pos] = x.nd;
  dp[0][0] = 1;
  for(int i = 1; i <= cnt.size(); i++) {
    for(int j = 0; j <= k; j++) {
      dp[i][j] = (dp[i][j] + dp[i-1][j]) % MOD;
      if(j) dp[i][j] = (dp[i][j] + (dp[i-1][j-1] * aux[i]) % MOD) % MOD;
    }
  }
  cout << dp[cnt.size()][k] << "\n";
}
