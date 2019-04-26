#include <bits/stdc++.h>
using namespace std;

int x, y, a, b;
vector<pair<int, int>> v;

int main(){
  cin >> x >> y >> a >> b;
  for(int j = b; j <= y; j++)
    for(int i = max(j+1, a); i <= x; i++)
      v.push_back({i, j});

  sort(v.begin(), v.end());
  cout << v.size() << endl;
  for(auto x : v) cout << x.first << " " << x.second << endl;
}
