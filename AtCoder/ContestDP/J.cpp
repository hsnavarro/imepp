#include <bits/stdc++.h>
using namespace std;

typedef long double ld;

const int N = 300 + 5;
const ld EPS = 1e-9;

ld dp[N][N][N];
int mark[N][N][N];
int n, a, cnt[3]; 

ld dpf(int a, int b, int c) {
  if(mark[a][b][c]) return dp[a][b][c];
  mark[a][b][c] = 1;
  if(!a and !b and !c) return dp[a][b][c] = 0;
  
  ld nd = n, ad = a, bd = b, cd = c;
  ld part_a = 0, part_b = 0, part_c = 0;

  if(a-1 >= 0) part_a = ad/nd * dpf(a-1, b, c);
  if(b-1 >= 0) part_b = bd/nd * dpf(a+1, b-1, c);
  if(c-1 >= 0) part_c = cd/nd * dpf(a, b+1, c-1);
  
  return dp[a][b][c] = nd/(ad+bd+cd) * (1 + part_a + part_b + part_c);
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  for(int i = 1; i <= n; i++) cin >> a, cnt[a-1]++;
  cout << fixed << setprecision(20) << dpf(cnt[0], cnt[1], cnt[2]) << "\n";  
}
