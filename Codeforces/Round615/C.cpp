#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int t;
ll n;
vector<ll> divs;

void go(ll n) {
  divs.clear();
  for(ll i = 2; i*i <= n; i++) {
    if(n % i == 0) {
      divs.push_back(i);
      if(i*i != n) divs.push_back(n/i);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> t;
  while(t--) {
    cin >> n;
    go(n);
    int cond = 0;
    for(auto a : divs) {
      for(auto b : divs) {
        ll c = 0;
        if(n % (a*b) == 0) c = n/(a*b);
        if(a != b and b != c and a != c and c >= 2) {
          cout << "YES\n";
          cout << a << " " << b << " " << c << "\n";
          cond = 1;
          break;
        }
      }
      if(cond) break;
    }
    if(!cond) cout << "NO\n";
  }
}
