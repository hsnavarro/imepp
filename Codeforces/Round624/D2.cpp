#include <bits/stdc++.h>
using namespace std;

const int N = 2e4 + 5;

typedef long long ll;

const int INF = 0x3f3f3f3f;
int t;
ll a, b, c;

ll find(ll b) {
  ll op1 = c/b * b;
  ll op2 = op1 + b;
  if(abs(op1 - c) < abs(op2 - c)) return op1;
  return op2;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> t;
  while(t--) {
    cin >> a >> b >> c;
    ll res = INF, resa, resb, resc;
    for(ll ax = 1; ax < N; ax++) {
      for(ll bx = ax; bx < N; bx += ax) {
        ll cx = find(bx); 
        if(abs(ax - a) + abs(bx - b) + abs(cx - c) < res) {
          res = abs(ax - a) + abs(bx - b) + abs(cx - c);
          resa = ax, resb = bx, resc = cx;
        }
      }
    }
    cout << res << "\n";
    cout << resa << " " << resb << " " << resc << "\n";
  }
}
