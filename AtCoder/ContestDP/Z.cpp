#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

typedef long double ld;
typedef long long type;

struct line { type b, m; };

int nh, pos;
line hull[N];

bool check(line s, line t, line u){
  //attention for overflow
  return ld (u.b - t.b)/(t.m - u.m) > ld (t.b - s.b)/(s.m - t.m);
}

void update(line s){
  if(nh == 1 and hull[nh-1].b == s.b) nh--;
  if(nh > 0 and s.m >= hull[nh-1].m) return;
  while(nh >= 2 and !check(hull[nh-2], hull[nh-1], s)) nh--;
  pos = min(pos, nh);
  hull[nh++] = s;
}

type eval(int id, type x) { return hull[id].b + hull[id].m*x; }

type query(type x){
  while(pos+1 < nh and eval(pos, x) > eval(pos+1, x)) pos++;
  return eval(pos, x);
}

int n;
type dp[N], c, h[N];
line s;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n >> c;
  for(int i = 1; i <= n; i++) cin >> h[i];

  dp[1] = 0;
  s = {c + h[1]*h[1] + dp[1], -2*h[1]};
  update(s);
  for(int i = 2; i <= n; i++) {
    dp[i] = h[i]*h[i] + query(h[i]);
    s = {c + h[i]*h[i] + dp[i], -2*h[i]};
    update(s);
  }
  cout << dp[n] << "\n";
}
