#include <bits/stdc++.h>
using namespace std;

int n;
map<string, int> f;

int main(){
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  string s;
  for(int i = 0; i < n; i++) cin >> s, f[s]++;
  int mx = 0;
  for(auto x : f) mx = max(mx, x.second);

  cout << mx << endl;
}
