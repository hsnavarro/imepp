#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define pb push_back

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;

#define db(x) cerr << #x << " == " << x << endl 
#define _ << ", " << 

int n, xh, yh, xw, yw;

int x, y;
vector<pair<int, int>> v;
vector<int> a;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  cin >> xh >> yh >> xw >> yw;
  if(xh > xw) swap(xh, xw), swap(yh, yw);
  while(n--) {
    cin >> x >> y;
    if(x < min(xh, xw) or x > max(xh, xw)) continue;
    if(y < min(yh, yw) or y > max(yh, yw)) continue;
    v.pb({x, y});
  }

  if(yh <= yw) sort(v.begin(), v.end());
  else sort(v.begin(), v.end(), 
      [](pair<int, int> a, pair<int, int> b) {
        return a.st == b.st ? a.nd > b.nd : a.st < b.st;
      });

  for(auto x : v) a.pb(x.nd);
  if(yh > yw) reverse(a.begin(), a.end());
  vector<int> dp;
  for(int i = 0; i < a.size(); i++) {
    int l = upper_bound(dp.begin(), dp.end(), a[i]) - dp.begin();
    if(l == dp.size()) dp.pb(a[i]);
    else dp[l] = a[i];
  }
  cout << dp.size() << "\n";
}
