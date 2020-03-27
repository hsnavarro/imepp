#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define pb push_back

typedef long long ll;
const ll MOD = 1e9 + 9;

ll add (ll a, ll b) {
  if(a + b >= MOD) return a + b - MOD;
  return a + b;
}

ll dp[130][1005], amt[130][1005];
int k, b;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> k >> b;
  dp[1][1%k] = 1;
  amt[1][1%k]++;
  amt[1][0]++;

  for(int i = 1; i < b; i++) {
    for(int j = 0; j < k; j++) {
      if(!amt[i][j]) continue;
      auto &a = dp[i+1][(2*j + 1) % k];
      a = add(add(a, dp[i][j]), amt[i][j]);
      auto &b = amt[i+1][(2*j + 1) % k];
      b = add(b, amt[i][j]);
      auto &c = dp[i+1][(2*j) % k];
      c = add(c, dp[i][j]);
      auto &d = amt[i+1][(2*j) % k];
      d = add(d, amt[i][j]);
    }
  }
  cout << dp[b][0] << "\n";
}
