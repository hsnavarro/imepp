#include <bits/stdc++.h>
using namespace std;
 
const int N = 1000 + 5;
const int INF = 0x3f3f3f3f;
 
struct sh{
  int st, end, song, stage;
};
 
sh show[N];
int n, num, cnt, dp[2*N][(1 << 12)];
vector<int> times, endIn[2*2*N];
 
int main(){
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> num;
    for(int j = 0; j < num; j++){
      cnt++;
      cin >> show[cnt].st >> show[cnt].end >> show[cnt].song;
      show[cnt].stage = i;
    }
  }
  for(int i = 1; i <= cnt; i++) {
    times.push_back(show[i].st);
    times.push_back(show[i].end);
  }
  sort(times.begin(), times.end());
  times.resize(unique(times.begin(), times.end()) - times.begin());
  for(int i = 1; i <= cnt; i++) {
    show[i].st = lower_bound(times.begin(), times.end(),  show[i].st) - times.begin() + 1;
    show[i].end = lower_bound(times.begin(), times.end(), show[i].end) - times.begin() + 1;
  }
  for(int i = 1; i <= cnt; i++) endIn[show[i].end].push_back(i);
 
  for(int i = 0; i < 2*N; i++) 
    for(int j = 0; j < (1 << 12); j++) dp[i][j] = -INF;
  dp[1][0] = 0;
  for(int t = 2; t <= times.size() + 1; t++){
    for(int b = 0; b < (1 << n); b++){
      dp[t][b] = max(dp[t][b], dp[t-1][b]);
      for(auto x : endIn[t]){
        if(b & (1 << show[x].stage)){
          dp[t][b] = 
            max({dp[t][b], 
              dp[show[x].st][b - (1 << show[x].stage)] + show[x].song});
          }
        dp[t][b] =
          max(dp[t][b], dp[show[x].st][b] + show[x].song);
      }
    }
  }
  int ans = dp[times.size()+1][(1 << n) - 1];
  cout << (ans < 0 ? -1 : ans) << "\n";
}
