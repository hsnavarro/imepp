#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define pb push_back

typedef long long ll;
typedef long double ld;

ld dp[(1 << 9)][13][2];
string s;
int mask, a, b, sum;

ld prob(int x) {
  if(x > 7) x = 14 - x;
  ld aux = 1.0*x - 1.0;
  return aux/36.0;
}

string build(int x) {
  string aux;
  for(int k = 0; k <= 12; k++) if((1 << k) & x) aux += char(int(k + 1 + '0'));
  return aux;
}

int eval(int x) {
  string s = build(x);
  return s.size() ? stoi(s) : 0;
}

int sum_dig(int x) {
  int ver = 0;
  for(int k = 0; k <= 12; k++) if((1 << k) & x) ver += k+1;
  return ver;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> s >> a >> b;
  sum = a + b;
  for(auto x : s) mask += (1 << (x - '1'));
 
  for(int msk = 0; msk < (1 << 9); msk++)
    for(int sm = 0; sm <= 12; sm++) dp[msk][sm][1] = 1e14;

  for(int msk = 0; msk < (1 << 9); msk++) {
    for(int sm = 2; sm <= 12; sm++) {
      int count = 0;
      for(int sub = msk; sub > 0; sub = (sub-1) & msk) {
        if(sum_dig(sub) != sm) continue;
        count++;
        ld acc1 = 0.0, acc2 = 0.0;
        for(int k = 2; k <= 12; k++) acc1 += prob(k)*dp[msk - sub][k][0];
        for(int k = 2; k <= 12; k++) acc2 += prob(k)*dp[msk - sub][k][1];
        dp[msk][sm][0] = max(dp[msk][sm][0], acc1);
        dp[msk][sm][1] = min(dp[msk][sm][1], acc2);
      }
      if(!count) dp[msk][sm][0] = dp[msk][sm][1] = ld(eval(msk));
    }
  }

  ld mx = -1.0, mn = 1e18;
  int mxb = 0, mnb = 0, cnt = 0;
  for(int sub = mask; sub > 0; sub = (sub-1) & mask) {
    if(sum_dig(sub) != sum) continue;
    cnt++;
    ld acc1 = 0.0, acc2 = 0.0;
    for(int k = 2; k <= 12; k++) acc1 += prob(k)*dp[mask - sub][k][0];
    for(int k = 2; k <= 12; k++) acc2 += prob(k)*dp[mask - sub][k][1];
    if(acc1 > mx) mx = acc1, mxb = sub;
    if(acc2 < mn) mn = acc2, mnb = sub;
  }


  string mxs = build(mxb), mns = build(mnb);

  cout << fixed << setprecision(5);
  if(!cnt) {
    ld ans = ld(eval(mask));
    cout << -1 << " " << ans << "\n";
    cout << -1 << " " << ans << "\n";
  } else {
    cout << mns << " " << mn << "\n";
    cout << mxs << " " << mx << "\n";
  }
}
