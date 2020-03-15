#include <bits/stdc++.h>
using namespace std;

const int N = 1005;

string a, b;
int dp[N][N];

int lcs(int i, int j){
  if(dp[i][j] != -1) return dp[i][j];
  if(i == 0 or j == 0) return dp[i][j] = 0;
  if(a[i-1] == b[j-1]) dp[i][j] = 1 + lcs(i-1, j-1);
  else dp[i][j] = max(lcs(i-1, j), lcs(i, j-1));
  return dp[i][j];
}

int main(){
  ios_base::sync_with_stdio(0), cin.tie(0);
  memset(dp, -1, sizeof dp);
  cin >> a >> b;
  cout << lcs(a.size()-1, b.size()-1) << endl;
}
