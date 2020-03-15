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

const int N = 200 + 5;

int n, cond = 1, st[N], val[N];
string s;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  cin >> s;
  for(int i = 0; i < n; i++) {
    if(!st[i]) st[i] = 1, val[i] = 0;
    for(int j = i+1; j < n; j++) {
      if(s[j] >= s[i]) continue;
      if(!st[j]) st[j] = 1, val[j] = val[i]^1;
      else if(st[j] != val[i]^1) { cond = 0; break; }
    }
  }
  if(!cond) cout << "NO\n";
  else {
    cout << "YES\n";
    for(int i = 0; i < n; i++) cout << val[i];
    cout << "\n";
  }
}
