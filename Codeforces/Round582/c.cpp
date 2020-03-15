#include <bits/stdc++.h>
using namespace std;

#define int long long

int q, n, m, sum;
set<int> aux;
vector<int> cycle;

int32_t main(){
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> q;
  while(q--){
    cin >> n >> m;
    cycle.clear(), aux.clear();
    int ax = m, sum = 0;
    while(!aux.count(ax%10)) 
      aux.insert(ax%10), cycle.push_back(ax%10), ax += m;
    int a = cycle.size();
    for(auto x : cycle) sum += x;
    int ans = ((n/m)/a) * sum, r = ((n/m) % a);
    for(int i = 0; i < r; i++) ans += cycle[i];
    cout << ans << "\n";
  }
}
