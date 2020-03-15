#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

int n, a;
vector<int> szs, up, down;

int main(){
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  for(int i = 0; i < 2*n; i++) cin >> a, szs.push_back(a);
  sort(szs.begin(), szs.end());
  for(int i = 0; i < n; i++) up.push_back(szs[i]);
  for(int i = n; i < 2*n; i++) down.push_back(szs[i]);
  reverse(down.begin(), down.end());
  for(auto x : up) cout << x << " ";
  cout << endl;
  for(auto x : down) cout << x << " ";
    cout << endl;
  cout << "ok" << endl;  
  int mn = 2e9, mx = -INF;
  for(int i = 0; i < n; i++){
    cout << up[i] + down[i] << endl;
    mn = min(mn, up[i] + down[i]);
    mx = max(mx, up[i] + down[i]);
  }
  cout << mx - mn << "\n";
}
