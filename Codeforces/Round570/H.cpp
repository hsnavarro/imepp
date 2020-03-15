#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 100 + 5;

int n, last[30];
string s;
ll k, dp[N][N], sum, ans, aux;

int32_t main(){
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n >> k >> s;

  for(int i = 0; i < 30; i++) last[i] = -1;
  for(int i = 0; i <= n; i++) dp[i][0] = 1;

  for(int i = 1; i <= n; i++) {
    for(int k1 = 1; k1 <= i+1; k1++){
      if(last[s[i-1] - 'a'] >= 1) dp[i][k1] -= dp[last[s[i-1] - 'a']-1][k1-1];
      dp[i][k1] = min(k, dp[i][k1] + dp[i-1][k1] + dp[i-1][k1-1]);
    }
    last[s[i-1] - 'a'] = i;
  }

  for(int i = n; i >= 0; i--)
    aux = min(k, dp[n][i]), sum += aux, ans += 1ll*(n-i)*aux, k -= aux;
  
  cout << (k ? -1 : ans) << "\n";
}
