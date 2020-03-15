#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define pb push_back

typedef long long ll;
typedef pair<int, int> pii;

const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int n, m, a;
ll sum[15];
ll ans;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n >> m;
  for(int i = 0; i < n; i++) cin >> a, sum[a]++;
  ll asum = 0;
  for(int i = 1; i <= m; i++) {
    ans += asum*sum[i];
    asum += sum[i];
  }
  cout << ans << "\n";
}
