#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define pb push_back

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;

const int INF = 0x3f3f3f3f;

// 1 2 3 4 5

int t, n, cond, l, r, mn, mx;
vector<int> a;

int main(){
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> t;
  while(t--){
    cond = 0;
    cin >> n;
    a.resize(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i+1 < n; i++){
      if(abs(a[i] - a[i+1]) >= 2) {
        cond = 1;
        cout << "YES\n";
        cout << i+1 << " " << i+2 << "\n";
        break;
      }
    }
    if(!cond) cout << "NO\n";
  }
}
