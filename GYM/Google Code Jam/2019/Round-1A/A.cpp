#include <bits/stdc++.h>
using namespace std;

mt19937_64 llrand(random_device{}());

int t, r, c, cnt, R, C;

bool valid(int x, int y){
  if(x == r or y == c) return false;
  if(r - c == x - y) return false;
  if(r + c == x + y) return false;
  return true;
}

int main(){
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> t;
  while(t-- and ++cnt){
    cin >> R >> C;
    r = c = 1;
    int moves = 1e7;
    vector<pair<int, int>> ans;
    set<pair<int, int>> vis;
    ans.push_back({1, 1});
    vis.insert({1, 1});
    while(moves--){
      int x = llrand() % R + 1; //1 to R
      int y = llrand() % C + 1; //1 to C
      if(valid(x, y) and !vis.count({x, y})){
        r = x, c = y;
        ans.push_back({x, y});
        vis.insert({x, y});
      }
    }
    cout << ans.size() << endl;
    cout << "Case #" << cnt << ": " << 
      (ans.size() == R*C ? "POSSIBLE" : "IMPOSSIBLE") << endl;
    if(ans.size() == R*C) for(auto x : ans) cout << x.first << " " << x.second << endl;
  }
}
