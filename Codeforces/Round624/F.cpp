#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define pb push_back

typedef long long ll;

const int N = 2e5 + 5;

int n, x[N], v[N];
vector<pair<int, int>> p;

ll bit1[N], bit2[N], ans;

void add(int p, int v, ll *bit) {
  for (p+=2; p<N; p+=p&-p) bit[p] += v;
}

ll query(int p, ll *bit) {
  ll r = 0;
  for (p+=2; p; p-=p&-p) r += bit[p];
  return r;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  for(int i = 0; i < n; i++) cin >> x[i];
  for(int i = 0; i < n; i++) cin >> v[i];
  for(int i = 0; i < n; i++) p.push_back({x[i], v[i]});
  sort(p.begin(), p.end());
  sort(v, v+n);
  for(auto &x : p) {
    x.nd = lower_bound(v, v+n, x.nd) - v + 1;
    ans += 1ll*x.st*query(x.nd, bit1) - query(x.nd, bit2);
    add(x.nd, 1, bit1);
    add(x.nd, x.st, bit2);
  }
  cout << ans << "\n";
  
}
