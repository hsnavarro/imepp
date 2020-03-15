#include <bits/stdc++.h>
using namespace std;

const int N = 2000 + 5;

int n, pos, ok[N], l, r;
string s;
pair<int, int> dp[N][N], ans;

bool cond1() { return l-1 >= 0; }
bool cond2() { return r+1 < n; }
pair<int, int> operator + (pair<int, int> a, pair<int, int> b){
  return {a.first + b.first, a.second + b.second} ;
}

int main(){
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> s;
  cin >> n;
  for(int i = 0; i < n; i++) cin >> pos, ok[pos-1] = 1;
  n = s.size();
  for(l = 0; l < n; l++){
    for(r = n-1; r >= 0; r--){
      if(l == r) dp[l][r] = max(dp[l][r], {ok[l], 1});
      if(cond1() and cond2() and l-1 <= r+1 and s[l-1] == s[r+1]) 
        dp[l][r] = max(dp[l][r], dp[l-1][r+1] + 
            make_pair((l-1 == r+1) ? ok[l-1] : ok[r+1] + ok[l-1], (l-1 == r+1) ? 1 : 2));
      if(cond1() and l-1 <= r)
        dp[l][r] = max(dp[l][r], dp[l-1][r]);
      if(cond2() and l <= r+1)
        dp[l][r] = max(dp[l][r], dp[l][r+1]);
      ans = max(ans, dp[l][r]);
    }
  }
  cout << ans.second << "\n";
}
