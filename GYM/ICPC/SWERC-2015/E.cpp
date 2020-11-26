#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MOD = 2147483647;
const int N = 2e3 + 5;

// dp[position][last base] = number of ways

int lastBase;
int point[N];
int n, dp[N][N];

bool overlap(int la, int ra, int lb, int rb) {
  if(la > ra) swap(la, ra);
  if(lb > rb) swap(lb, rb);

  if(max(la, lb) < min(ra, rb)) return true;
  return false;
} 

int add(int a, int b) {
  if(a + b >= MOD) return a + b - MOD;
  return a + b;
}

int32_t main() {
  cin >> n;
  cin >> lastBase;
  for(int i = 0; i < n; i++) cin >> point[i];

  dp[0][lastBase] = 1;

  for(int i = 0; i + 1 < n; i++) {
    for(int j = 1; j <= n+1; j++) {
      if(overlap(point[i], j, point[i+1], point[i])) 
        dp[i+1][point[i]] = add(dp[i+1][point[i]], dp[i][j]);

      if(overlap(point[i], j, point[i+1], j)) 
        dp[i+1][j] = add(dp[i+1][j], dp[i][j]);
    }
  }

  int sum = 0;
  for(int j = 1; j <= n+1; j++) sum = add(sum, dp[n-1][j]);
  cout << sum << "\n";
}
