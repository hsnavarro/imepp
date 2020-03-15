#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

string a;
int dp[N][2];

int main() {
  cin >> a;
  a = '0' + a;
  int n = a.size();
  dp[n-1][0] = a[n-1] - '0';
  dp[n-1][1] = 10 - (a[n-1] - '0');

  for(int i = n-2; i >= 0; i--) {
    int x = a[i] - '0';
    dp[i][0] = min(dp[i+1][0] + x, dp[i+1][1] + x + 1);
    dp[i][1] = min(dp[i+1][0] + 10 - x, dp[i+1][1] + 10 - x - 1);
  }
  cout << dp[0][0] << "\n";
}
