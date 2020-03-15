#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define pb push_back

typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const ld EPS = 1e-9;
const int MOD = 1e9+7;

const ll N = 1e4 + 5;

ll res = LINF, resa, resb, resc;
ll a, b, c, t;
vector<int> divs;

void find(ll x) {
  divs.clear();
  for(ll i = 1; i*i <= x; i++) {
    if(x % i == 0) {
      divs.pb(i);
      if(i*i != x) divs.pb(x/i);
    }
  }
}

void test(ll bin) {
  ll sum = abs(bin - b);
  ll opc1 = (c/bin) * bin;
  ll opc2 = opc1 + bin;
  ll ansa, ansc;

  if(abs(c - opc1) < abs(c - opc2)) ansc = opc1, sum += abs(c - opc1);
  else ansc = opc2, sum += abs(c - opc2);

  ll mn = LINF;
  find(bin);
  for(auto x : divs) {
    if(abs(x - a) < mn) mn = abs(x-a), ansa = x;
  }
  sum += mn;
  if(sum < res) res = sum, resa = ansa, resb = bin, resc = ansc;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> t;
  while(t--) {
    cin >> a >> b >> c;
    res = LINF;
    for(ll x = 0; x < N; x++) test(b+x);
    for(ll x = 0; x < N and b-x > 0; x++) test(b-x);
    cout << res << "\n";
    cout << resa << " " << resb << " " << resc << "\n";
  }

}
