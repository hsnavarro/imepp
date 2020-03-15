#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define pb push_back

typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const ld EPS = 1e-9;
const int MOD = 1e9+7;

const int N = 1e5 + 5;
ll n, a, b;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  while(n--) {
    cin >> a >> b;
    ll aux = b - a;
    if(!aux) cout << 0 << "\n";
    else if(aux > 0 and aux & 1) cout << 1 << "\n";
    else if(aux < 0 and (aux % 2 == 0)) cout << 1 << "\n";
    else cout << 2 << "\n";
  }
}
