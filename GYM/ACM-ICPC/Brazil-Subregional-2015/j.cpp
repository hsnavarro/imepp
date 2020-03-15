#include <bits/stdc++.h>
using namespace std;

int j, r, sum[501], ans, id, mx, x;

int main(){
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> j >> r;
  for(int i = 0; i < j*r; i++) {
    cin >> x;
    id = i%j + 1;
    sum[id] += x;
    if(mx <= sum[id]) mx = sum[id], ans = id;
  }
  cout << ans << "\n";
}
