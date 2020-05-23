#include <bits/stdc++.h>
using namespace std;

#define pb push_back

typedef long long ll;

int n, m;
vector<ll> b, p;
vector<ll> sums, ans;

void bt(int i, ll left, ll right) {
  if(i == m) {
    if(left == right) sums.pb(2ll*left);
    return;
  }

  bt(i+1, left, right);
  bt(i+1, left+p[i], right);
  bt(i+1, left, right+p[i]);
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n >> m;
  b.resize(n);
  for(int i = 0; i < n; i++) cin >> b[i];
  p.resize(m);
  for(int i = 0; i < m; i++) cin >> p[i];
  bt(0, 0, 0);

  for(auto x : b) 
    for(auto y : sums) ans.pb(x+y);

  sort(ans.begin(), ans.end());
  ans.resize(unique(ans.begin(), ans.end()) - ans.begin());

  for(auto x : ans) cout << x << "\n";
}
