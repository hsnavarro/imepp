#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

#define st first
#define nd second

typedef pair<int, int> pii;
typedef long long ll;

const ll LINF = 0x3f3f3f3f3f3f3f3f;

int q, n, k, a;
int l, r;

int main(){
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> q;
  while(q--){
    int l = -INF, r = INF;
    cin >> n >> k;
    for(int i = 0; i < n; i++) cin >> a, l = max(l, a-k), r = min(r, k+a);
    //cout << "l, r: " << l << " " << r << endl;
    cout << ((l <= r) ? r : -1) << "\n";
  }
}
