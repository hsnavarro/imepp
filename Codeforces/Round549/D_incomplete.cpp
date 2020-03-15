#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 0x3f3f3f3f3f3f3f3f;

ll n, k, a, b, x = INF, y = -INF;

ll case1(ll i, ll esc){
  if(esc == 1) return abs(a - b + i*k);
  if(esc == 2) return abs(a + b + i*k);
  if(esc == 3) return abs(i*k - a - b);
  return abs(b - a + i*k);
}

int main(){
  cin >> n >> k;
  cin >> a >> b;

  for(ll esc = 1; esc <= 4; esc++){
    for(ll i = 1; i <= n; i++){
      if(((n*k) % case1(i, esc)) == 0) 
        x = min(x, (n*k)/case1(i, esc)), y = max(y, (n*k)/case1(i, esc));
    }
  }
  cout << x << " " << y << endl;
}
