#include <bits/stdc++.h>
using namespace std;

int n, b, mn, mx, cnt;
set<int> a;

int main(){
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  for(int i = 0; i < n; i++) cin >> b, a.insert(b);
  auto it = a.begin();
  mn = *it;
  it = a.end(), it--;
  mx = *it;
  cout << mx - mn + 1 - a.size() << endl;
}
