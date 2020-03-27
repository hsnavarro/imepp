#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define pb push_back

typedef long long ll;
typedef pair<int, int> pii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

double ans;
int n;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  for(int i = n; i >= 1; i--) ans += 1.0*i*(i-1);
  ans = ans/(1.0*n);
  cout << fixed << setprecision(10) << ans << "\n";
}
