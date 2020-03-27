#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define pb push_back

typedef long long ll;
const int N = 1e6 + 5;
int cmp[N], ans, pos, x;
vector<int> p;

void sieve() {
  for(ll i = 2; i < N; i++) if(!cmp[i]) {
    p.push_back(i);
    for(ll j = i*i; j < N; j += i) cmp[j]= 1;
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  sieve();
  cin >> x;
  while(x >= 4) {
    pos = 0;
    while(cmp[x - p[pos]]) pos++;
    x -= 2*p[pos];
    ans++;
  }
  cout << ans << "\n";
}
