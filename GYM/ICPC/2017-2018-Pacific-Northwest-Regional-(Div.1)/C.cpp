#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define pb push_back

typedef long long ll;

ll a, b, sum;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> a >> b;
  for(ll x = 1; x <= (int) 1e6; x++) {
    for(ll k = ((a+x-1)/x)*x; k <= b; k += x) {
      if(x > k/x) continue;
      sum += x;
      if(k/x != x) sum += k/x;
    }
  }
  cout << sum << "\n";
}
