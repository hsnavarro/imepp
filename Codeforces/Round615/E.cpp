#include <bits/stdc++.h>
using namespace std;

#define int long long

int n, m, sum;

int32_t main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n >> m;
  vector<vector<int>> v(n+1, vector<int> (m+1));

  for(int i = 1; i <= n; i++) 
    for(int j = 1; j <= m; j++) cin >> v[i][j];
  
  for(int j = 1; j <= m; j++) {
    vector<int> cnt(n);
    int mn = n;
    for(int i = 1; i <= n; i++) {
      int pos = (i - 1) % n + 1, correct_pos, correction;
      if(v[i][j] >= j and (v[i][j] - j) % m == 0) 
        correct_pos = (v[i][j] - j)/m + 1;
      else continue;

      if(pos < correct_pos) pos += n;
      correction = pos - correct_pos;
      assert(correction < n);
      cnt[correction]++;
    }
    for(int i = 0; i < n; i++) mn = min(mn, n - cnt[i] + i);
    sum += mn;
  }
  cout << sum << "\n";
}
