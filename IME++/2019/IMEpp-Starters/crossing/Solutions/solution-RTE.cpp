#include <bits/stdc++.h>
using namespace std;

const int N = 105;

string a, b;
int dp[N][N];

int main(){
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> a >> b;
  for(int i = 1; i <= a.size(); i++){
    for(int j = 1; j <= b.size(); j++){
      if(a[i-1] == b[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
      else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
    }
  }
  cout << dp[a.size()][b.size()] << endl;
}
