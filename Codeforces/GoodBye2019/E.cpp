#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define pb push_back

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;

const int INF = 0x3f3f3f3f;
const int N = 1e3 + 5;

int n, x[N], y[N];
vector<pair<ld, pair<int, int>> > v;

ld dist(int i, int j) {
  return sqrt((x[i] - x[j])*(x[i] - x[j]) + (y[i] - y[j])*(y[i] - y[j]));
}

int main(){
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  for(int i = 1; i <= n; i++) cin >> x[i] >> y[i];

  for(int i = 1; i <= n; i++){
    for(int j = i+1; j <= n; j++){
      v.push_back({dist(i, j), {i, j}});
      cout << "i, j, dist: " << i << " " << j << " " << dist(i, j) << "\n";
    }
  }
  sort(v.begin(), v.end());
  for(auto x : v) {
    cout << x.st << " " << x.nd.st << " " << x.nd.nd << "\n";
  }
}
