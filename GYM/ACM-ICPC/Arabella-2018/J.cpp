#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define pb push_back

typedef long long ll;
typedef pair<int, int> pii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

const int N = 1e5 + 5;

string s;
int dist[N];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> s;
  int cnt = 0;
  ll ans = 0;

  if(s == "0") return cout << 2 << endl, 0;

  int seq = 0;
  for(int i = 0; i < s.size(); i++) {
    int val = s[i] - '0';
    if(val <= 5) ans += val, ans -= max(2*(seq-1), 0);
    else ans += 10 - val + 1, seq++;
  }
  ans -= max(2*(seq-1), 0);
  cout << ans << "\n";
}
