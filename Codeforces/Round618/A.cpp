#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define pb push_back

typedef long long ll;
typedef pair<int, int> pii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

const int N = 2e5 + 5;

ll t, n, a[N];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> t;
  while(t--){
    cin >> n;
    int ans = 0;
    ll sum = 0;
    for(int i = 0; i < n; i++) {
      cin >> a[i];
      if(!a[i]) a[i]++, ans++;
      sum += a[i];
    }
    while(!sum) sum++, ans++;
    cout << ans << "\n";
  }
}
