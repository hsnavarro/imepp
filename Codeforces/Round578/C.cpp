#include <bits/stdc++.h>
using namespace std;

#define int long long

int gcd(int a, int b) { return b ? gcd(b, a%b) : a; }

int n, m, q, g, sx, sy, ex, ey;

int32_t main(){
  cin >> n >> m >> q;
  g = gcd(n, m);
  while(q--){
    cin >> sx >> sy >> ex >> ey;
    int reg1 = (sx == 1) ? (sy-1)/(n/g) : (sy-1)/(m/g);
    int reg2 = (ex == 1) ? (ey-1)/(n/g) : (ey-1)/(m/g);
    cout << (reg1 == reg2 ? "YES\n" : "NO\n");
  }
}
