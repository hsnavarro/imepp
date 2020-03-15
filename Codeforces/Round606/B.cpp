#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define st first
#define nd second

typedef pair<int, int> pii;
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

int t, n, a, cnt;
set<int> s;

int main(){
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> t;
  while(t--){
    s.clear();
    cnt = 0;
    cin >> n;
    while(n--) {
      cin >> a;
      if(!(a & 1)) s.insert(a);
    }
    while(s.size()) {
      int ax = *s.rbegin();
      s.erase(ax);
      ax = ax/2;
      if(!(ax & 1)) s.insert(ax);
      cnt++;
    }

    cout << cnt << "\n";

  }
}
