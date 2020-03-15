#include <bits/stdc++.h>
using namespace std;

#define int long long

const int INF = 0x3f3f3f3f3f3f3f3f;

int l, c, cnt;
map<vector<string>, int> sum;
map<string, int> val;
string grid[105][105];
set<string> sz;

int32_t main(){
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> l >> c;
  for(int i = 0; i <= l; i++){
    for(int j = 0; j <= (i == l ? c-1 : c); j++){
      cin >> grid[i][j];
      if(i < l and j < c) val[grid[i][j]] = INF, sz.insert(grid[i][j]);
    }
  }
   
  for(int i = 0; i < l; i++){
    vector<string> aux;
    for(int j = 0; j <= c; j++){
      if(j == c) sum[aux] = stoi(grid[i][j]);
      else aux.push_back(grid[i][j]);
    }
  }

  for(int j = 0; j < c; j++){
    vector<string> aux;
    for(int i = 0; i <= l; i++){
      if(i == l) sum[aux] = stoi(grid[i][j]);
      else aux.push_back(grid[i][j]);
    }
  }

  while(cnt != sz.size()){
    for(auto el : sum){
      int ok = 1, sval = el.second, num = 0;
      string id = "";
      for(auto x : el.first) {
        if(val[x] != INF) sval -= val[x];
        else {
          if(id.size() and x != id) ok = 0;
          else id = x, num++;
        }
      }
      if(num and ok) val[id] = sval/num, cnt++;
    }
  }

  for(auto x : val) cout << x.first << " " << x.second << "\n";
}
