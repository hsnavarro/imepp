#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define pb push_back

typedef long long ll;
typedef pair<int, int> pii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9+7;

int t, n;
string s;
map<pair<int, int>, int> v;
map<pair<int, int>, int> pos;


int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> t;
  while(t--) {
    v.clear();
    pos.clear();
    int cond = 0, l = -INF, r = INF, x = 1, y = 1;
    cin >> n;
    cin >> s;
    v[{x, y}] = 1;
    pos[{x, y}] = -1;
    for(int i = 0; i < n; i++) {
      if(s[i] == 'U') y++;
      if(s[i] == 'D') y--;
      if(s[i] == 'L') x--;
      if(s[i] == 'R') x++;

      if(v[{x, y}]) { 
        cond = 1;
        if((i - pos[{x, y}]) < (r-l+1)) {
          l = pos[{x, y}] + 1;
          r = i; 
        }
        pos[{x, y}] = i;
      }
      else v[{x, y}] = 1, pos[{x, y}] = i;
      
    }
    if(cond) cout << l+1 << " " << r+1 << "\n";
    else cout << -1 << "\n";
  }
}
