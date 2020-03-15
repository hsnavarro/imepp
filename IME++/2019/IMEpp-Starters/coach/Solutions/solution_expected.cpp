#include <bits/stdc++.h>
using namespace std;

#define int long long

const int INF = 0x3f3f3f3f;
int n, x, d, cnt, s[20];

int32_t main(){
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n >> x >> d;
  for(int i = 0; i < n; i++) cin >> s[i];
  
  for(int i = 1; i < (1 << n); i++){
    int sum = 0, mx = -INF, mn = INF;
    for(int j = 0; j < n; j++)
      if(i & (1 << j)) sum += s[j], mx = max(mx, s[j]), mn = min(mn, s[j]);
    if(sum >= x and mx-mn <= d) cnt++;
  }

  cout << cnt << endl;
}
