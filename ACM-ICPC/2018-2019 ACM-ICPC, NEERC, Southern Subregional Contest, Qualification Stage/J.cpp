#include <bits/stdc++.h>
using namespace std;

long long a, b, x, y;

int main(){
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> a >> b >> x >> y;
  long long mdc = __gcd(x, y);
  x /= mdc, y /= mdc;
  cout << min(a/x, b/y) << endl;
}
