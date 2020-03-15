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
 
const int N = 100 + 5;
 
int t, n, m, x;
int a[N];
set<int> inp;
 
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> t;
  while(t--) {
    inp.clear();
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < m; i++) cin >> x, inp.insert(x);
    
    int cond = 1;
 
    for(int i = 0; i < n; i++) {
      for(int j = 0; j+1 < n; j++) {
        if(a[j] > a[j+1]) {
          if(!inp.count(j+1)) { cond = 0; break; }
          else swap(a[j], a[j+1]);
        }
      }
      if(!cond) break;
    }
    cout << (cond ? "YES\n" : "NO\n");
  }
}
