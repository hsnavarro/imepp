#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
const int INF = 0x3f3f3f3f;

int n, val, a[N], dp[N][2], ans[N];
//decrescente
//dp[i][0] = dp[i-1][0] se i-1 estiver na decrescente a[i-1] > a[i]
//dp[i][0] = a[i-1] se i-1 não estiver na decrescente dp[i-1][1] > a[i]
//pegar menor crescente

//crescente
//dp[i][1] = dp[i-1][1] se i-1 estiver na crescente a[i-1] < a[i]
//dp[i][1] = a[i-1] se i-1 não estiver na decrescente dp[i-1][0] < a[i]
//pegar maior decrescente

int main(){
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  for(int i = 1; i <= n; i++) cin >> a[i];
  for(int i = 1; i <= n; i++) dp[i][0] = INF, dp[i][1] = -1;
  
  dp[1][0] = -1, dp[1][1] = INF;
  for(int i = 2; i <= n; i++){
    if(a[i-1] > a[i]) dp[i][0] = dp[i-1][0];
    if(dp[i-1][1] > a[i]) dp[i][0] = min(dp[i][0], a[i-1]);

    if(a[i-1] < a[i]) dp[i][1] = dp[i-1][1];
    if(dp[i-1][0] < a[i]) dp[i][1] = max(dp[i][1], a[i-1]);

    if(dp[i][0] == INF and dp[i][1] == -1) return cout << "NO" << endl, 0;
  }
  cout << "YES" << endl;
  
  dp[n][0] != INF ? val = 1 : val = 0;
  for(int i = n; i >= 1; i--){
    ans[i] = val;
    if(val == 1){
      if(a[i-1] <= a[i] or dp[i-1][0] != dp[i][0])  val ^= 1;
    }
    else if(a[i-1] >= a[i] or dp[i][1] != dp[i-1][1]) val ^= 1;
  } 
  for(int i = 1; i <= n; i++) cout << ans[i] << " ";
  cout << endl;
}
