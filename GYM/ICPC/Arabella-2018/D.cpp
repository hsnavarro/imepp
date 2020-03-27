#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define pb push_back

typedef long long ll;
typedef pair<int, int> pii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

const int N = 1e6 + 5;

int n, m;
ll a[N], b[N], mdc;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n >> m;
  for(int i = 0; i < n; i++) cin >> a[i];
  for(int i = 0; i < m; i++) cin >> b[i], mdc = __gcd(mdc, b[i]);
  int cond = 1;
  for(int i = 0; i+1 < n; i++) if((a[i+1] - a[i]) % mdc != 0) cond = 0;
  cout << (cond ? "Yes\n" : "No\n");
}
