#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

#define st first
#define nd second

typedef pair<int, int> pii;
typedef long long ll;

const ll LINF = 0x3f3f3f3f3f3f3f3f;

ll q, k, n, a, b;

int main(){
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> q;
  while(q--){
    cin >> k >> n >> a >> b;
    ll ans = min ( (k-n*b+a-b-1)/(a-b) - 1, n);
    if(ans < 0) cout << -1 << "\n";
    else cout << ans << "\n";
  }

}
