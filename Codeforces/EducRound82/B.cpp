#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define st first
#define nd second

typedef long long ll;
typedef pair<int, int> pii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

int t;
ll n, g, b;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> t;
  while(t--) {
    cin >> n >> g >> b;
    ll good = (n+1)/2;
    ll per_good = good/g;
    ll rest = good%g;
    ll per_bad = per_good + (rest > 0) - 1;
    //cout << per_good << " " << per_bad << "\n";
    cout << max(n, per_good*g + per_bad*b + rest) << "\n";
  }
}
