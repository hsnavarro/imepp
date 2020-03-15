#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define pb push_back

typedef long long ll;
typedef pair<int, int> pii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

const int N = 3e5 + 5;

ll n, a[N];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  for(int i = 1; i <= n; i++) cin >> a[i];
  sort(a+1, a+n+1);
  ll sum = 0, ans = 0;
  for(int k = 2, l = 1, r = n; k <= n; k++) {
    if(k % 2 == 0) sum += a[r] - a[l], r--, l++;
    ans += sum;
    cout << ans << " ";
  }
  cout << "\n";
}
