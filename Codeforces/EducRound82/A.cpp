#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define st first
#define nd second

typedef long long ll;
typedef pair<int, int> pii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

const int N = 1e5 + 5;

int t;
string s;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> t;
  while(t--) {
    cin >> s;
    int l = -1, r = -1;
    for(int i = 0; i < s.size(); i++) {
      if(s[i] == '1') {l = i; break; }
    }
    for(int i = s.size() - 1; i >= 0; i--) {
      if(s[i] == '1') { r = i; break; }
    }



    int cnt = 0;
    if(l != -1) for(int i = l; i <= r; i++) if(s[i] == '0') cnt++;
    cout << cnt << "\n";
  }

}
