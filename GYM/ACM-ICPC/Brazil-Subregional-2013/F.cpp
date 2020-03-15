#include <bits/stdc++.h>
using namespace std;

#define int long long
#define st first
#define nd second
#define pb push_back

typedef pair<int, int> pii;
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

const int N = 2e5 + 5;

int n, tot, a[N], aux, sum[N], ans;
map<int, bool> have;

int32_t main(){
  ios_base::sync_with_stdio(0), cin.tie(0);
  while (cin >> n) {
    for(int i = 0; i < n; i++) cin >> a[i], tot += a[i];
    for(int i = 1; i <= n; i++) sum[i] = a[i-1] + sum[i-1];
    for(int i = 0; i <= n; i++) have[sum[i]] = 1, have[sum[i] + tot] = 1;
    for(int i = 0; i <= n; i++) if(tot%3 == 0 and have[sum[i]] and have[sum[i] + tot/3] and have[sum[i] + (2*tot)/3]) ans++;
    cout << ans/3 << "\n";
    for(int i = 0; i <= n; i++) sum[i] = 0;
    have.clear();
    ans = 0, tot = 0;
  }
} 
