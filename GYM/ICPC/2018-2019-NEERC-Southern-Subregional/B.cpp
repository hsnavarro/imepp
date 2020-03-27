#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int n, h, low, sum, fall[N], l[N], r[N], mx;

int main(){
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n >> h;
  memset(fall, 63, sizeof(fall));
  for(int i = 0; i < n; i++) cin >> l[i] >> r[i];
  fall[0] = sum = 0;
  for(int i = 1; i < n; i++) sum += l[i] - r[i-1], fall[i] = sum;
  for(int i = 0; i < n; i++){
    low = lower_bound(fall, fall + n + 1, fall[i] + h) - fall - 1;
    mx = max(mx, r[low] - l[i] + h - fall[low] + fall[i]);
  }
  cout << mx << endl;
}
