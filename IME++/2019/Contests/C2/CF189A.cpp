#include <bits/stdc++.h>
using namespace std;

int a, b, c, n, mx;

int main(){
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n >> a >> b >> c;
  for(int x = 0; x <= 4000; x++){
    for(int y = 0; y <= 4000; y++){
      if((n - a*x - b*y)%c == 0 and (n - a*x - b*y)/c >= 0) mx = max(mx, x+y+ (n - a*x - b*y)/c );
    }
  }
  cout << mx << endl;
}
