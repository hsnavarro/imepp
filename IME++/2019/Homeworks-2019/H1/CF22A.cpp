#include <bits/stdc++.h>
using namespace std;

int n, v[105];

int main(){
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  for(int i = 0; i < n; i++) cin >> v[i];
  sort(v, v + n);
  int mn = v[0];
  int up = upper_bound(v, v + n, mn) - v;
  if(up < n) cout << v[up] << endl;
  else cout << "NO" << endl;
}
