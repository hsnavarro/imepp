#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n, k, dp[N];
set<int> s;
vector<int> rem;

int mex(set<int> &s) {
  for(int i = 0; i <= k; i++) if(!s.count(i)) return i;
  return -1;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n >> k;
  rem.resize(n);
  for(int i = 0; i < n; i++) cin >> rem[i];

  for(int i = 1; i <= k; i++) {
    s.clear();
    for(auto x : rem) if(i - x >= 0) s.insert(dp[i-x]);
    dp[i] = mex(s);
  }

  cout << (dp[k] ? "First\n" : "Second\n");
}
